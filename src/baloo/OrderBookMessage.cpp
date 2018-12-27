#include "OrderBookMessage.h"

boost::posix_time::ptime OrderBookMessage::getTimestamp() {
    return timestamp;
}

void OrderBookMessage::setTimestamp(boost::posix_time::ptime timestamp) {
    this->timestamp = timestamp;
}

double OrderBookMessage::getPrice() {
    return price;
}

void OrderBookMessage::setPrice(double price) {
    this->price = price;
}

double OrderBookMessage::getQuantity() {
    return quantity;
}

void OrderBookMessage::setQuantity(double quantity) {
    this->quantity = quantity;
}

OrderDirection OrderBookMessage::getDirection() {
    return direction;
}

void OrderBookMessage::setDirection(OrderDirection direction) {
    this->direction = direction;
}
