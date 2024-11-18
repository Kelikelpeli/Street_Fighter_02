#ifndef Ken_H
#define Ken_H
#pragma once
#include "Character.h"

class Ken : public Character
{
public:
    Ken();
    virtual ~Ken();

    void InitCharacter() override;
    void UpdateCharacter(float deltaTime) override;

    void Ken::UpdateCharacter(float deltaTime);


};

#endif