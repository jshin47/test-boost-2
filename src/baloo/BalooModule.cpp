#include <boost/python.hpp>

#include "OrderDirection.h"
#include "OrderBookSnapshot.h"
#include "OrderBookMessage.h"

#include "../util/PythonTimeConverter.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(baloo) {
    enum_<OrderDirection>("OrderDirection")
        .value("Ask", Ask)
        .value("Bid", Bid)
        .export_values()
        ;


    void (OrderBookSnapshot::*applyMessage)(OrderBookMessage&) = &OrderBookSnapshot::apply;
    void (OrderBookSnapshot::*applyPythonList)(boost::python::list&) = &OrderBookSnapshot::apply;

    class_<OrderBookSnapshot>("OrderBookSnapshot")
        .def_readonly("asks", &OrderBookSnapshot::asksPythonDictionary)
        .def_readonly("bids", &OrderBookSnapshot::bidsPythonDictionary)
        .def("apply", applyMessage)
        .def("apply", applyPythonList)
        ;

    class_<OrderBookMessage>("OrderBookMessage")
        .add_property("timestamp", &OrderBookMessage::getTimestamp, &OrderBookMessage::setTimestamp)
        .add_property("price", &OrderBookMessage::getPrice, &OrderBookMessage::setPrice)
        .add_property("quantity", &OrderBookMessage::getQuantity, &OrderBookMessage::setQuantity)
        .add_property("direction", &OrderBookMessage::getDirection, &OrderBookMessage::setDirection)
        ;

    bind_datetime();
}