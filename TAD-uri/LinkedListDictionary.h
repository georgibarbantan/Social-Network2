//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_LINKEDLISTDICTIONARY_H
#define PROIECT_SDA_LINKEDLISTDICTIONARY_H


template<class K, class V>
class Dictionary;

template<class K, class V>
class Node {
private:
    K key;
    V value;
    Node<K, V> *next;
public:
    Node(K key, V value) : key(key), value(value) {
        this->next = nullptr;
    }

    friend class Dictionary<K, V>;

};

template<class K, class V>
class Dictionary {
private:
    Node<K, V> *first;
    int size;

    Dictionary<K, V> *searchReference(K key) {
        if (this->size == 0) return nullptr;
        Dictionary<K, V> *p = first;
        while (p->next != nullptr) {
            if (p->key == key) return p;
            p = p->next;
        }
    }

public:
    Dictionary() {
        this->first = nullptr;
        size = 0;
    }

    void add(K key, V value) {
        if (first == nullptr) {
            first = new Node<K, V>(key, value);
            this->size++;
        } else {
            Node<K, V> *p = first;
            while (p->next != nullptr && p->key != key) {
                p = p->next;
            }
            if (p->key == key) {
                p->value = value;
            } else {
                p->next = new Node<K, V>(key, value), this->size++;
            }

        }
        this->size++;
    }

    V get(K key) {
        Node<K, V> *p = first;
        while (p != nullptr) {
            if (p->key == key) return p->value;
            p = p->next;
        }
        return {};
    }

    int remove(K key) {
        Dictionary<K, V> *position = searchReference(key);
        if (position != nullptr && position->key == key) {
            Dictionary<K, V> *p = first;
            if (position == first) this->first = position->next;
            else {
                while (p->next != position) p = p->next;
                p->next = position->next;
            }
            this->size--;
            delete position;
            return 1;
        }
        return 0;
    }

    int getSize() {
        return this->size;
    }
};

#endif //PROIECT_SDA_LINKEDLISTDICTIONARY_H
