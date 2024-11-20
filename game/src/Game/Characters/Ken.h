#ifndef Ken_H
#define Ken_H
#include "Game/Characters/Character.h"

class Ken : public Character
{
public:
    Ken();
    virtual ~Ken();

    void InitCharacter() override;
    void UpdateCharacter(float deltaTime) override;
    void DrawCharacter() override;

   // void Ken::UpdateCharacter(float deltaTime);
private:
    void LoadKenAnimations();

};

#endif