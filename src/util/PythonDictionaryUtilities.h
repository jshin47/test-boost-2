#ifndef BALOO_LIBRARY_H
#define BALOO_LIBRARY_H

#include <boost/python.hpp>

using namespace boost::python;

namespace BalooUtil {

    // Converts a C++ map to a python dict
    template <class K, class V>
    dict toPythonDict(std::map<K, V> map) {
        typename std::map<K, V>::iterator iter;
        dict dictionary;
        for (iter = map.begin(); iter != map.end(); ++iter) {
            dictionary[iter->first] = iter->second;
        }
        return dictionary;
    }
}

#endif // BALOO_LIBRARY_H