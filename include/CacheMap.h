//
// Created by Basajaun on 27/9/22.
//

#ifndef CACHESIM_CACHEMAP_H
#define CACHESIM_CACHEMAP_H

#include "SharedDefines.h"

typedef struct {
    int blMp;
    int blMc;
    int tag;
    int setId;

    int lruCounter;
    int fifoCounter;

    bool free;
    bool dirty;
    bool replaced;
} CacheElement;

/**
 * Matriz de punteros a CacheElement
 */
class CacheMap {

public:
    CacheMap(int algorithm, int setSize);

    bool addrCheckByDirect(int tag, int blMp, int blMc);
    bool addrCheckBySetAssoc(int tag, int blMp, int setId);
    bool addrCheckByTotAssoc(int blMp);
    void manageCacheInsertion(CacheElement* ce);

    /**
     * LRU
     */
    int getBlockNumAndReduceLRU(int set = -1);
    int getLruOrEmpty(int set = -1);

    /**
     * FIFO
     */

    void display();

private:
    CacheElement* m_cacheDir[CACHE_NUM_BLOCKS]{};
    int m_algorithm;
    int m_setSize;
};

#endif //CACHESIM_CACHEMAP_H