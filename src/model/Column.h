#pragma once

#include <string>

#include <boost/dynamic_bitset.hpp>
#include <utility>

#include "RelationalSchema.h"

class Column {
friend RelationalSchema;

private:
    std::string name;
    unsigned int index;
    RelationalSchema const* schema;

public:
    Column(RelationalSchema const* schema, std::string name, int index) :
            name(std::move(name)),
            index(index),
            schema(schema) {}

    unsigned int getIndex() const { return index; }
    std::string getName() const { return name; }
    RelationalSchema const* getSchema() const { return schema; }

    std::string toString() const { return "[" + name + "]";}
    explicit operator std::string() const { return toString(); }
    explicit operator Vertical() const;

    bool operator==(const Column& rhs) const;
};