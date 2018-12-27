#include "OrderBookSnapshot.h"

#include <boost/python.hpp>

#include "../util/PythonDictionaryUtilities.h"

using namespace boost::python;

dict OrderBookSnapshot::asksPythonDictionary() {
    if (asksNeedsEnumeration) {
        lastEnumeratedAsksPythonDictionary = BalooUtil::toPythonDict<double, double>(asks);
        asksNeedsEnumeration = false;
    }
    return lastEnumeratedAsksPythonDictionary;
}

dict OrderBookSnapshot::bidsPythonDictionary() {
    if (bidsNeedsEnumeration) {
        lastEnumeratedBidsPythonDictionary = BalooUtil::toPythonDict<double, double>(bids);
        bidsNeedsEnumeration = false;
    }
    return lastEnumeratedBidsPythonDictionary;
}

void OrderBookSnapshot::apply(OrderBookMessage& message) {
    messages.push_back(message);
    std::map<double, double>& whichMap = (message.getDirection() == Ask) ? asks : bids;

    if (message.getQuantity() > 0)
        whichMap.emplace(message.getPrice(), message.getQuantity());
    else
        whichMap.erase(message.getPrice());

    if (whichMap == asks)
        asksNeedsEnumeration = true;
    else
        bidsNeedsEnumeration = true;
}

void OrderBookSnapshot::apply(boost::python::list& pythonMessageList) {
    for (int i = 0; i < len(pythonMessageList); ++i) {
        OrderBookMessage& message = boost::python::extract<OrderBookMessage&>(pythonMessageList[i]);
        apply(message);
    }
}