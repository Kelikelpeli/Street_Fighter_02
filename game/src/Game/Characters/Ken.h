#ifndef Ken_H
#define Ken_H
#pragma once
#include "Character.h"

class Ken : public Character
{
public:
    Ken();
    ~Ken();

    void InitCharacter() override;
    void UpdateCharacter(float deltaTime) override;
    void DrawCharacter() override;

   // void Ken::UpdateCharacter(float deltaTime);
private:
    void LoadKenAnimations();

};

#endif