#ifndef OBJECTMANAGER_H
#define	OBJECTMANAGER_H

#include <list>
#include "Noncopyable.h"
#include "Object.h"

class ObjectManager final : public Noncopyable {
public:
    ObjectManager() = default;
    ObjectManager(const ObjectManager& orig) = delete;
    virtual ~ObjectManager();
    void render();
private:
    std::list<Object*> objects;
};

#endif	/* OBJECTMANAGER_H */

