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

Yes, this project is actually dead and has been dead for about 2 years. 

This readme was created recently in order to document the scope and effort put into the project and provide a brief technical overview of the technologies used as well as the features
implemented. The scope of this project was ambitious, and in retrospect probably even delusional for a senior in high school just starting his college applications. What little of a glimpse this documentation may provide into DungeonRaider's construction I hope will at
least address the challenges faced in designing this, and provide proof that not all of those sleepless nights upstairs during high school were spent playing Unreal Tournament.

### Causes of Death

* Architectural asphyxiation
* Premature optimization
* Cargo-culting OOP design patterns
* Lack of time

Beginners in video game development often set out to code a game and decide halfway through that they need a game engine instead. That is what happened to DungeonRaider. 

Game code becomes spaghettified not in response to the addition of features, but to the possibility of adding features. This has been covered exhaustively in many a forum thread; naive developers like me tend not to listen. 

The first symptom of architectural asphyxiation will occur as enemies are added to the game. As Mario vs. the Goombas becomes Mario vs. the Goombas And Maybe Some Koopas Or Other Enemies, the single class `Goomba` blows up in the game's code, splitting up into `Enemy`, `Goomba`, `Koopa`, and God knows what our single developer hero will think of next. For me, I wanted to let the player possess enemies, so naturally the player character and all enemies had to inherit from the same base class - `Player` and `Enemy` soon turned into `Entity`, `Actor`, `Character`, and `Controller`, even before I had drawn up my first enemy sprite. 

The problem here isn't that our single hero developer has a ridiculously overactive imagination; it's that the engineer in our developer's mind hasn't gotten around to telling the designer in our developer to shut the hell up and no that can't be done yet, because first of all the engineer can't talk with that pacifier in his mouth and second of all he's barely just learned to walk when the designer in the developer's mind has been painting his own Sistine Chapel for the past 15 years. 

So the tendency is to abstract away the hard details and architect from afar, with the little-understood ivory tower concepts that our engineer-developer knows. A spaghettified mess looks a little better from a hundred feet back, and certainly better from 30,000 feet in the air. Before we know it our hero is what Joel Sposky calls an [Architecture Astronaut](http://www.joelonsoftware.com/articles/fog0000000018.html) and he's mistaken the constant refactoring of code that does nothing for the self-congratulatory act of doing something.
