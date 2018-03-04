/*
 * The indexmap class is a collection that stores objects
 * and associates integers with those objects. 
 */
#pragma once

#include <vector>
#include <string>
#include <map>

template<typename T>
class Indexmap
{
private:
    std::vector <T> ind; //Maps int->T
    std::map<T, int> objects; //Maps T->int
public:

    Indexmap()
    {
    }

    /*
     * Insert an object in the map. Returns the index ascociated with
     * the object. The index returned will start at 0 for the first
     * object inserted and increase by 1 for each object inserted.
     *
     * If the object already is in the map, the index it was given when it was
     * first inserted will be returned.
     *
     * Runs in time O(1)
     */
    int getIndex(T o)
    {
        std::pair<T, int> p(o, ind.size());
        auto r = objects.insert(p);
        if (r.second) {
            ind.push_back(o);
        }
        return r.first->second;
    }

    /*
     * Get the object ascociated with the integer i. The integer must be
     * already be ascociated with an object in the map.
     *
     * Runs in time O(1)
     */
    T getObject(int i)
    {
        return ind[i];
    }

    /*
     * Get the current size of the indexmap.
     *
     * Runs in time O(1)
     */
    int size()
    {
        return ind.size();
    }
};

