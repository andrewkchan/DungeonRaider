# DungeonRaider
A 2D isometric game engine written in C++ by Andrew Chan. 

Rendering is done through OpenGL using the [SFML multimedia API](https://github.com/SFML/SFML), which also provides the foundation for the engine's input system.

## Overview

### Features

DungeonRaider's rendering pipeline includes several custom OpenGL shaders that allow for depth-sorted rendering of sprites using user-defined depth maps. Automatic depth sorting also occurs
on objects depending on their y-position relative to the bottom of the screen - closer objects (closer to the bottom of the screen) will automatically have a higher depth than farther objects - that is, closer objects
will automatically obscure farther objects as per a traditional isometric view.

Game worlds may also have 3 dimensions, so that characters can move up and down across the Z-axis of a world without having their depth affected as described above.

A very rudimentary UI is included, featuring functions to display text objects onscreen with values subscribed to various members of objects in the scene graph.

## Post Mortem

Yes, this project is actually dead and has been dead for about 2 years. This readme was created recently in order to document the scope and effort put into the project and provide a brief technical overview of the technologies used as well as the features
implemented. The scope of this project was ambitious, and in retrospect probably even delusional for a senior in high school just starting his college applications. What little of a glimpse this documentation may provide into DungeonRaider's construction I hope will at
least address the challenges faced in designing this, and provide proof that not all of those sleepless nights upstairs during high school were spent playing Unreal Tournament.
