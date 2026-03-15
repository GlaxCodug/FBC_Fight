#ifndef FBC_H
#define FBC_H

#include <stdbool.h>

typedef enum {
    Misc,
    Strike,
    Grab,
    Projectile
} FBC_PUNCH_ENUM_MOVETYPE;

typedef enum {
    Ground,
    Air
} FBC_PUNCH_ENUM_MOVEENVIROMENT;

typedef enum {
    High,
    Mid,
    Low
} FBC_PUNCH_ENUM_MOVEHEIGHT;

typedef enum {
    No_Effect,
    Crumple,
    Tumble,
    Launch,
    Freeze,
    Dizzy,
    WallBounce
} FBC_PUNCH_ENUM_MOVEEFFECT;

typedef enum {
    Neutral,
    Invincible,
    Armored,
    Counter,
    Parry
} FBC_PUNCH_ENUM_HURTBOXSTATE;

typedef enum {
    HitBox,
    HurtBox
} FBC_PUNCH_ENUM_BOXTYPE;

typedef struct {
    FBC_PUNCH_ENUM_MOVEEFFECT Type;
    
    union {
        int Duration;
    } Data;
} FBC_PUNCH_EFFECT;

typedef struct {
    int Damage;
    int KnockBack;
    int LaunchDist;
    bool OTG;
    bool ChipDamage;
    bool GuardBreak;
    FBC_PUNCH_EFFECT Effect;
} FBC_PUNCH_HITBP;

typedef struct {
    FBC_PUNCH_ENUM_HURTBOXSTATE State;
    
    union {
        int StateDuration;
    } Data;
} FBC_PUNCH_HURTBP;

typedef struct {
    FBC_PUNCH_ENUM_BOXTYPE Type;
    
    union {
        FBC_PUNCH_HITBP HitBox;
        FBC_PUNCH_HURTBP HurtBox;
    } Properties;
} FBC_PUNCH_HBP;

#endif