#ifndef BALOO_ORDER_BOOK_MESSAGE_H
#define BALOO_ORDER_BOOK_MESSAGE_H

#include <tuple>
#include <map>
#include <string>
#include <sstream>
#include <vector>

#include <boost/python.hpp>
#include <boost/date_time.hpp>
#include <boost/date_time/posix_time/ptime.hpp>

#include "OrderDirection.h"

class OrderBookMessage {
public:
    boost::posix_time::ptime getTimestamp();
    void setTimestamp(boost::posix_time::ptime timestamp);
    double getPrice();
    void setPrice(double price);
    double getQuantity();
    void setQuantity(double quantity);
    OrderDirection getDirection();
    void setDirection(OrderDirection direction);
private:
    boost::posix_time::ptime timestamp;
    double price;
    double quantity;
    OrderDirection  direction;
};


#endif //BALOOCONTRIB_ORDERBOOKMESSAGE_H
