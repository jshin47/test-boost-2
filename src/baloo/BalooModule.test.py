#!/usr/bin/env python

import unittest

import datetime

from baloo import OrderBookMessage, OrderDirection, OrderBookSnapshot

class BalooModuleTests(unittest.TestCase):

    def test_message_retains_values(self):
        message = OrderBookMessage()
        message.price = 10
        self.assertEqual(message.price, 10)
        message.quantity = 100
        self.assertEqual(message.quantity, 100)
        message.direction = OrderDirection.Ask
        self.assertEqual(message.direction, OrderDirection.Ask)
        now = datetime.datetime.now()
        message.timestamp = now
        self.assertEqual(message.timestamp, now)

    def test_snapshot_applies_message(self):
        snapshot = OrderBookSnapshot()

        message = OrderBookMessage()
        message.price = 10
        message.quantity = 100
        message.direction = OrderDirection.Ask
        message.timestamp = datetime.datetime.now()

        snapshot.apply(message)

        self.assertEqual(len(snapshot.asks), 1)
        self.assertEqual(len(snapshot.bids), 0)

        message.quantity = 100
        message.price = 11
        snapshot.apply(message)
        self.assertEqual(len(snapshot.asks), 2)
        self.assertEqual(len(snapshot.bids), 0)

        message.direction = OrderDirection.Bid
        message.quantity = 100
        snapshot.apply(message)
        self.assertEqual(len(snapshot.asks), 2)
        self.assertEqual(len(snapshot.bids), 1)

        message.direction = OrderDirection.Ask
        message.quantity = 0
        snapshot.apply(message)
        self.assertEqual(len(snapshot.asks), 1)
        self.assertEqual(len(snapshot.bids), 1)

    def test_snapshot_applies_message_list(self):
        message1 = OrderBookMessage()
        message1.quantity = 100
        message1.price = 10
        message1.direction = OrderDirection.Ask
        message1.timestamp = datetime.datetime.now()
        message2 = OrderBookMessage()
        message2.quantity = 100
        message2.price = 10
        message2.direction = OrderDirection.Bid
        message2.timestamp = datetime.datetime.now()
        message_list = [message1, message2]

        snapshot = OrderBookSnapshot()
        snapshot.apply(message_list)
        self.assertEqual(len(snapshot.asks), 1)
        self.assertEqual(len(snapshot.bids), 1)


if __name__ == '__main__':
    unittest.main()
