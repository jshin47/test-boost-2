PYTHON_ADD_MODULE(
    baloo
    BalooModule.cpp
    OrderDirection.h
    OrderBookSnapshot.h
    OrderBookSnapshot.cpp
    OrderBookMessage.h
    OrderBookMessage.cpp
    ../util/PythonDictionaryUtilities.h
    ../util/PythonTimeConverter.h
)
FILE(COPY BalooModule.test.py DESTINATION .)
ADD_TEST(NAME BalooModule COMMAND ${PYTHON_EXECUTABLE} BalooModule.test.py)