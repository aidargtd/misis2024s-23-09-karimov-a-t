#ifndef ICONTAINERBASE_HPP
#define ICONTAINERBASE_HPP

class IContainerBase {
public:
    virtual ~IContainerBase() = default;

    virtual void add(int value) = 0;
    virtual bool remove(int value) = 0;
    virtual bool contains(int value) const = 0;

};

#endif
