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
} FBC_PUNCH_ENUM_HURTBOX_STATE;

typedef enum {
    HitBox,
    HurtBox
} FBC_PUNCH_ENUM_BOXTYPE;

typedef struct {
    FBC_PUNCH_ENUM_MOVEEFFECT Type;
    
    union {
        int Duration;
        //more stats will be added later
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
} FBC_PUNCH_HITBOX_PROPERTIES;

typedef struct {
    FBC_PUNCH_ENUM_HURTBOX_STATE State;
    
    union {
        int StateDuration;
        //more stats will be added later
    } Data;
} FBC_PUNCH_HURTBOX_PROPERTIES;

typedef struct {
    FBC_PUNCH_ENUM_BOXTYPE Type;
    
    float SizeX;
    float SizeY;
    float SizeZ;
    float PosX;
    float PosY;
    float PosZ;

    union {
        FBC_PUNCH_HITBOX_PROPERTIES HitBox;
        FBC_PUNCH_HURTBOX_PROPERTIES HurtBox;
    } Properties;
} FBC_PUNCH_BOX;

typedef struct
{
    char name[50];
    FBC_PUNCH_ENUM_MOVETYPE Types[2];
    FBC_CORE_ANIMATION_TRACK Animation;
    FBC_PUNCH_BOX Boxs[10];
} FBC_PUNCH_MOVE;

typedef struct
{
    FBC_PUNCH_MOVE ListOfMoves[50];
    FBC_CORE_ANIMATION_STATEMACHINE CurrentAnimation;
} FBC_PUNCH_MOVELIST;

typedef struct
{
    char Name[100];
    union
    {
        FBC_CORE_ASSET_MODEL CharacterModel;
        FBC_CORE_ASSET_SPRITE CharacterSprite;
    } Body;
    int Health;
    int Speed;

    struct
    {
        struct
        {
            bool CanRun;
            union
            {
                int RunSpeed;
                struct
                {
                    bool CanDash;
                    int DashDistance;
                } Dashing;
            };
        } GroundMovement;
        struct
        {
            struct
            {
                bool MultiJump;
                int AmountJumps;
            } Jumping;

            struct
            {
                bool AirDash;
                struct
                {
                    bool MultiAirDash;
                    int AmountOfAirDashs;
                };
            } AirMovement;
            
            struct 
            {
                int Weight;
            } Physics;
        } AirMovement;
    } Movement;
    
    FBC_PUNCH_MOVELIST MoveSet;
} FBC_PUNCH_CHARACTER_PROFILE;

typedef struct
{
    char Name;
    
    int TotalFrames;

    bool Looping;
} FBC_CORE_ANIMATION_TRACK;

typedef struct
{
    char AnimationName;
    
    int CurrentFrame;
} FBC_CORE_ANIMATION_STATEMACHINE;

typedef struct
{
    char Name[100];
    char FilePath[300];
    int Width;
    int Height;
} FBC_CORE_ASSET_SPRITE;

typedef struct
{
    char Name[100];
    char FilePath[300];
    int VertexCount;
} FBC_CORE_ASSET_MODEL;

#endif