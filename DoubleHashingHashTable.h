//
// Created by silva on 3/15/2023.
//

#ifndef HASHTABLE_DOUBLEHASHINGHASHTABLE_H
#define HASHTABLE_DOUBLEHASHINGHASHTABLE_H

#include "OpenAddressingHashTable.h"

template <typename K, typename V>
class DoubleHashingHashTable : public OpenAddressingHashTable<K,V> {
private:
    // The secondary hash function. Many different functions can
    // be used here. The function used here is a common one, with
    // different (usually prime number) constants used where the 7 is.
    int H2(const K& key) const {
        return 7 - this->Hash(key) % 7;
    }

public:
    DoubleHashingHashTable(int initialCapacity = 11) :
            OpenAddressingHashTable<K,V>(initialCapacity) {
    }

protected:
    // Returns the bucket index for the specified key and i value using the
    // double hashing probing sequence.
    int Probe(const K& key, int i) const override {
        return (this->Hash(key) + i * H2(key)) % this->table.size();
    }
};

#endif //HASHTABLE_DOUBLEHASHINGHASHTABLE_H
