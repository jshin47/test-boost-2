#ifndef BALOO_ORDER_BOOK_SNAPSHOT_H
#define BALOO_ORDER_BOOK_SNAPSHOT_H

#include <map>
#include <list>
#include <boost/python.hpp>

#include "OrderBookMessage.h"

class OrderBookSnapshot {
public:
    boost::python::dict asksPythonDictionary();
    boost::python::dict bidsPythonDictionary();

    void apply(OrderBookMessage& message);
    void apply(boost::python::list& pythonMessageList);
private:
    std::list<OrderBookMessage> messages;
    std::map<double, double> asks;
    std::map<double, double> bids;

    boost::python::dict lastEnumeratedAsksPythonDictionary;
    boost::python::dict lastEnumeratedBidsPythonDictionary;
    bool asksNeedsEnumeration = true;
    bool bidsNeedsEnumeration = true;
};


#endif //BALOO_ORDER_BOOK_SNAPSHOT_H
