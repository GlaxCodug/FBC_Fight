
***FBC Fight is currently in the conceptual/Early Development stage. The repository is empty while core architecture is being designed. Development updates will be posted as progress is made.***

The development of FBC Fight starts as of Today (03/08/2026). FBC Fight is going to be a fighting game first game engine which will come with all the necessary tools for creating a fighting game whether it be a traditional 2d fighter (Street Fighter, Fatal Fury, or Mortal Kombat), 3d fighters (Tekken, Virtua Fighter, or Soul Calibur), or platform fighters (Smash Bros, Brawlhalla, or Combo Devils) the list goes on. The architecture of FBC Fight is still in early development so anything below is up to changes in the future.

FBC Fight will also come with a built-in File/Code editor, Custom Scripting Language, Visual Coding Blocks, 3d modeler/Sprite editor, DAW, and Animation editor all of which will be there to optimize any files you have within the game engine.

# The Goal

The idea is to create an open source engine with the capabilities of creating a game as optimized as .kkrieger in which the game is only 98kb (which is absolutely mind boggling). The  goal for the engine itself is to manage to run both the engine and a game from it on a raspberry pi 4 model B with 2 gigs of ram.

I myself want FBC Fight to be accessible and without limits as I plan to leave this engine as open source. I will continue to work on this engine as I'd like to add new features and tools in the future and add more tools for other kinds of games, such as shooters, rpgs, simulators, etc.

# Current Planned Features

All of the features listed below are planned to be directly integrated into the engine itself as a monolithic game engine. For those who are unaware of what a monolithic game engine is, it means all tools are part of the application itself. There will be no need for external programs or separate applications associated with FBC Fight.

For example, assets, animations, scripts, and audio can all be created and edited directly inside FBC Fight without switching software similarly to how Roblox Studio does it.

**File/Code Editor/IDE**

Similarly to Godot, Roblox Studio, or GameMaker. FBC Fight will have a built in IDE that you all can use at any time in case you don't have one already. C# and C++ will be available for those who already have experience with Unity or Unreal Engine, as well as Lua is planned to be available as well for a more beginner friendly approach as well as a gateway to those already familiar with Roblox Studio. Within the Editor/IDE you can also work on your own plugins when that becomes an available resource

**Custom Scripting Language**

FBC Fight will come with its own scripting language for those who are already somewhat familiar with programming as a whole. This would allow those who are not as experienced to work on their own mechanics within their games as to not limit their ability to learn and develop

**Visual Coding Blocks**

FBC Fight will also come with a Block based coding method as well, I’m basing this off of GameSalad and Scratch as those two are the most beginner friendly approaches to those who have no knowledge about programming. With enough diligence and effort you can make quite well made systems using this method as I’ve experienced a similar thing back in middle school myself when making some of my first games.

**3D Modeler**

FBC Fight’s 3D modeler will allow the use of procedural asset loading within any of your games meaning you can save disk space for your players. The 3D modeler itself will come with this function already in place as anything made with this in mind will come as its own file type. You may still use your own model assets from other file extensions but they won't be compatible with procedural asset loading.

**Sprite Editor**

FBC will come with its own sprite editor so you may start a new piece of art from scratch, or use an already existing file in order to edit it within FBC Fight without the need for external programs.

**Animation Editor**

Both the 3D modeler and Sprite editor will come with an animation editor integrated into them, allowing you to create animation tracks on the spot without a need to leave the editors themselves

**DAW (Digital Audio Workstation)**

FBC Fight’s DAW will mainly be used for your own custom sounds and will come with a synthesizer so you may create your own sounds as well. I would suggest the use of soundfonts within the DAW as a MIDI and Piano Roll will be available as well.

**RollBack NetCode**

Yes, obviously FBC Fight will come with rollback integration. What do you take me for a monster? For those who don't know RollBack is a networking system that gives the most smooth and reliable gameplay currently as it doesn't delay player inputs as delay based netcode would. It became more widespread when it became open source in 2019 through GGPO in GitHub, it was first developed in 2006 and released in 2009 by Tony Cannon.

# Objects

**<ins>HitBox</ins>** - a space in either 2D/3D space or a segment in a 3D model that can be used to detect when it touches another HitBox or HurtBox during an attack

**<ins>HurtBox</ins>** - using either 2D/3D shapes or a model itself as the space that represents a collidable space of a entity, can be used for physics and combat

**<ins>HBP</ins>** - a list of properties that can be assigned to either HitBoxes or HurtBoxes to apply different affects

**<ins>Move</ins>** - a list of properties as well as a container for specific details of a animation, whether it be blocking, walking, jumping or attacking

**<ins>Character</ins>** - Entity object used to create a playable character within the game. Requires a CharacterProfile

**<ins>NPC</ins>** - Entity object used to create a non playable character within the game, they can be interacted with but will not have a gameplay centric AI. Requires Character Profile

**<ins>Bot</ins>** - Entity object used to create a non playable character within the game and interact with the world themselves, can be used as an opponent or team member. Requires CharacterProfile

**<ins>CharacterProfile</ins>** - An object that allows you to place all data and assets for a character within the object in an easy to understand format.

# How to make a character

Characters will require any of the 3 entity objects from above in order to create a character in game, the hierarchy for how it is made up would look like this

```
Entity Object (Character, NPC, or Bot)
	CharacterProfile
		Body (3D Model or 2D Sprite)
		MoveSet
			ListOfMoves
				Move1
					Animation
					HurtBoxes
						HBP (HurtBox selected on enum)
					HitBoxes
						HBP (HitBox selected on enum)
				Move2
					Animation
					HurtBoxes
						HBP (HurtBox selected on enum)
					HitBoxes
						HBP (HitBox selected on enum)
				SpecialMove1
					Animation
					HurtBoxes
						HurtBox (HurtBoxes can have their own HBP that will overide the main HBP. think of Dragon Ball Fighterz and Guilty Gear Strive that both have air invincable attacks or in the case of Guilty Gear, just upper body invincibility to air attacks)
							HBP (HurtBox selected on enum)
						HBP (HurtBox selected on enum)
					HitBoxes
						HitBox (HitBoxes can have their own HBP that will overide the main HBP. think of Soul Calibur 6 Mina, or Smash Bros Marth who have sweet spots on the tips of their swords where the attack generally tends to be better or have different effects)
							HBP (HitBox selected on enum)
						HBP (HitBox selected on enum)
```

This will be the List of Properties and Objects in a character
```
CharacterProfile (CharacterProfile Object):
  Name (String)
  Body (Model/Sprite Object)
  Health (Integer)
  WalkSpeed (Integer)
  CanRun (Bool)
	  True: RunSpeed (Integer)
	  False: ForwardDash (Bool)
		  True: DashDistance (Integer), DashSpeed (Integer)
		  False: Character cannot forward dash
  MultiJump (Bool)
	  True: Jumps (Integer)
	  False: Character only has one jump
  Gravity (Integer, Base gravity of character will be the gravity of the project. Changing this can make a character feel more floaty or heavy)
  MoveSet (MoveSet Object):
	  ListOfMoves (List)
		  Move (Move Object. Needs to be added manually):
			  Name (String)
			  Type (List, Enum):
				  MoveType1:
				  	Misc, Strike, Throw (Air/Ground), Projectile
				  MoveType2 (optional):
				  	Strike, Throw (Air/Ground), Projectile
			  Animation (AnimationTrack Object)
			  HurtBoxes (List, HurtBox Objects. Add HurtBox Objects manually)
			  	HurtBoxProperties (HBP Object, Enum. Applied to parent HurtBox List or Single HurtBox)
			  		Enum HurtBox:
			  			State (Enum. List of HurtBox states that can change during any specific animation)
								None, Invincible/Intangible, Armored, Counter, Parry, etc.)
			  	  			EffectDuration (Integer. Depending on the effect such as armor the integer would stand for how many hits the armor can tank before Breaking, ind would be the string used for infinite/indefinite)
			  HitBoxes (List, HitBox Objects. Add HitBox Objects manually)
			  	HitBoxProperties (HBP Object, Enum. Applied to parent HitBox List or Single HitBox):
				  	Enum HitBox:
						  Damage (Integer)
						  KnockBack (Integer)
						  LaunchDist (Integer. If attack has Launch property this will apply even if the opponent is standing on the ground, otherwise this will only apply to airborne opponents)
					  	OTG (Bool. These attacks can hit a knocked down opponent)
				  		StateEffects (Enum):
							  None, Crumple, Tumble, Launch, Freeze, Stun/Dizzy, WallBounce, etc.
							  	EffectDuration (Integer, In Frames for only some effects with examples such as Freeze, Stun/Dizzy, or Poison)
						  ChipDamage (Bool):
						  	True: Damage (Integer)
		 						False: Attack does not deal chip damage on block
						  GuardBreak (Bool):
						  	True: Attack gets guard break property on block
				  			False: Attack only applies basic effects on block
	  CurrentMove (Animation State Machine)
```
