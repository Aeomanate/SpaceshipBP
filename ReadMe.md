# Asteroids game
A classic video game is developing for training in creating and maintaining large codebase

## Currently implemented features
### General
* Used SFML, RapidJSON, GTest, better-enums.
* Cross-compilation on CMake 3.27: MSVS2019/MinGW-w64.
### MVC
* Controller, Core
  * `ListenersEmitters` - observer pattern interpretation in Qt/UE manner.
  * `LowLevelApplication` - it handles I/O from windows level, organizes a game loop.
  * `Application` - it a singleton contains all globally needed semi-related to ECS resources (configs, textures, etc). 
* Model, Simulation, ECS
    * Each of `Component` holds a map of <`EntityPtr`, `UserComponent`>.
    * Each of `Entity` can claim/reject a `Component` and get the value of it.
    * Each of `System` contained in and updated by a `Level` class.
      * Each of `UserLevel` provided by a `LevelProvider` 
        that delegates level creating to a `LevelCreatorsStorage`.
      * `LevelCreatorsStorage` holds unique lazy creator-function 
        taken from static-initialization stage for each `UserLevel`.
* View, Menus and Layers
  * Still as a stub.
  
### Utility
* Structure-intrusive automatic serialization solution like a code generation in UE.
  * Used a lot of C++20 concepts for replacing SFINAE.
  * Main classes:
    * `SerializableBase` - is common staff for serialization via RapidJSON.
    * `SerializableStruct` - is container and base class for user structure 
      contains several `SerializableVariable` and/or `SerializableStructs`.
      It iterates recursively on self members.
    * `SerializableVariable` - it contains an object of RapidJson-supported literal type 
      or third-party type which defined fromJson/toJson in `GameJsonConversions`/`StdJsonConversions` structures.
  * For user-usage defined several macro e.g. `SERI_V(...)`, `SERI_S(...)` & `SERI_C(...)`, etc. 
  * TODO: Implement a serializable representation of std::vector, std::array/c-array.   
* `FrameByFrame` - is an encapsulation of a sprite-sheet png-file
  * For each png-file exists a `ConfigTexture` object describes name, frame rate, 
    frame size, origin, orientation, etc.
  * `TextureProvider` - it used for create `FrameByFrame` object. 
    When application starts, it loads all textures that enumerated in a `ConfigTextures` object 
    via visitor pattern implemented in a `SerializableStruct` class via iterating on internal structure-members array. 

## SAST Tools
[PVS-Studio](https://pvs-studio.com/pvs-studio/?utm_source=website&utm_medium=github&utm_campaign=open_source) - static analyzer for C, C++, C#, and Java code.
