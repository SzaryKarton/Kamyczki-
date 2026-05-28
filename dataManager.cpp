#include "datamanager.h"

dataManager& dataManager::instance()
{
    static dataManager db;

    return db;
}
