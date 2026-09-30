#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class weaponBase : public AActor
{
    GENERATED_BODY()

public:

    UPROPERTY(EditDefaultOnly, Category="Combat")
    float damage = 35.f;

    UPROPERTY(EditDefaultOnly, Category="Combat")
    float fireRate = 0.12f;
    
    UPROPERTY(EditDefaultOnly, Category="Combat")
    float range = 3000.f;

    bool IsFiring;
    bool IsReloading;
    bool IsEquipping;

    void checkDead();                       // Mover ambos a otro componente que gestione la muerte.
    void HandleDeath();                     // El arma no tiene la responsabilidad de la muerte, solo de disparar.

    void FireWeapon_Server(FVector dir);

protected:
    virtual void doAttack();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////


UCLASS()
class APlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:

    // Gestión de vida 
    UPROPERTY(VisibleInstanceOnly, Category="State")    //  
    float CurrentHealth;                                //  Mover a un componente que gestione la vida del jugador.
                                                        //
    void TakeDmg(float dmg);                            //

    // Gestión de inventario                            // 
    UPROPERTY()                                         //
    TArray<AActor*> items;                              //  Mover a un componente que gestione el inventario del jugador
                                                        //
    void AddItem(AActor* newItem);                      //

    //Gestión de diálogo                                //  La función podría estar dentro de un componente 'Interact' del jugador
    void StartDialog(AActor* npc);                      //

    //Gestión de puntuación                             //  La función podría estar dentro de un componente que gestione los puntos del jugador.
    void AddPoints(int 32 pts);                         //

    UPROPERTY(EditDefaultOnly, Category="Combat")
    float BaseDamage = 25.f;

    UPROPERTY(EditDefaultOnly, Category="Combat")
    float CritMultiplier = 2.5f;

private:
    int32 score = 0;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////



// Es mejor que el ScoreManager conecte con el character y el haga de enlace entre ScoreManager y HUD.

UCLASS()
class UScoreManager : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public: 
    void AddScore(int32 Points);

private:
    int32 CurrentScore = 0;
    UMyGameHUD* HUD;
};

////////////////////////////////////////////////

void USCoreManager::AddScore(int32 Points)
{
    CurrentScore += Points;
    HUD->UpdateScoreDisplay(CurrentScore);
}