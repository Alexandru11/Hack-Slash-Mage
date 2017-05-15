#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object
{
    int a;
public:
    virtual ~Object ();
    //Object() //extra de mine

	virtual std::string ToString() const;
	virtual bool Equal(Object* other);
};

#endif
