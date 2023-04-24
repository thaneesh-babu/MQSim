#ifndef GC_INFO_H
#define GC_INFO_H

#include "queue"
#include "../ssd/NVM_Transaction_Flash.h"
#include "../nvm_chip/flash_memory/FlashTypes.h"

struct GCInfo {
    flash_block_ID_type BlockID;
    bool isActive;
    int responseTime;
    std::queue<NVM_Transaction_Flash*> AwaitingQueue;
};

class GCInfoInterface {
public:
    void addGCInfo(flash_block_ID_type BlockID);
    void removeGCInfo(flash_block_ID_type BlockID);
    void addTransaction(flash_block_ID_type BlockID, NVM_Transaction_Flash* transaction);
    void removeTransaction(flash_block_ID_type BlockID, NVM_Transaction_Flash* transaction);
    bool isGCActive(flash_block_ID_type BlockID);
    int getResponseTime(flash_block_ID_type BlockID);
    void setResponseTime(flash_block_ID_type BlockID, int responseTime);
    std::queue<NVM_Transaction_Flash*> getAwaitingQueue(flash_block_ID_type BlockID);
    void setAwaitingQueue(flash_block_ID_type BlockID, std::queue<NVM_Transaction_Flash*> awaitingQueue);

private:
    std::vector<GCInfo> GCInfoVector;
};

#endif // !GC_INFO_H