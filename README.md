Swrid
=====

*A kind of mixture between Tetris & Jewel*

Project by **David Perrai** & **Brice Thomas**, 2013

Graphics by **Maxime Dolo**

Video demo
----------
[Speed-up video](https://www.youtube.com/watch?v=TQxSR_iY0dA)

Screenshots
-----------
![Menu](screenshots/swridMenu.png)

![GameDebut](screenshots/swridDebut.png)

![GameFar](screenshots/swridGame.png)

Concept
-------

Firstly, we have a 14x12 grid :
<table>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
</table>

Then, we filled randomly the first four rows from the bottom with four types of element :
<table>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
  </tr>
  <tr>
    <td>2</td><td>4</td><td>3</td><td>1</td><td>4</td><td>1</td><td>2</td><td>3</td><td>4</td><td>2</td><td>1</td><td>3</td>
  </tr>
  <tr>
    <td>4</td><td>2</td><td>1</td><td>3</td><td>1</td><td>4</td><td>2</td><td>3</td><td>1</td><td>2</td><td>4</td><td>2</td>
  </tr>
  <tr>
    <td>1</td><td>2</td><td>4</td><td>3</td><td>1</td><td>2</td><td>4</td><td>1</td><td>2</td><td>3</td><td>4</td><td>1</td>
  </tr>
  <tr>
    <td>2</td><td>4</td><td>3</td><td>1</td><td>4</td><td>1</td><td>2</td><td>3</td><td>4</td><td>2</td><td>1</td><td>3</td>
  </tr>
</table>

Now, the player can swap two adjacent elements (from left, right, top and bottom).

Every time a swap occurred, each rows are pushed up and the first one is filled with new elements.

When the last row contains at least one element during two turns, the game is over.

Thus, the player must remove elements by forming groups of at least three elements of the same type. Some examples :
<table>
  <tr>
    <td>1</td><td>1</td><td>1</td>
  <tr>
</table>
<table>
  <tr>
    <td>1</td><td>1</td><td>1</td>
  <tr>
  <tr>
    <td></td><td></td><td>1</td>
  <tr>
</table>
<table>
  <tr>
    <td>2</td><td>2</td><td></td>
  <tr>
  <tr>
    <td></td><td>2</td><td></td>
  <tr>
</table>
<table>
  <tr>
    <td></td><td>2</td><td></td>
  <tr>
  <tr>
    <td></td><td>2</td><td></td>
  <tr>
  <tr>
    <td></td><td>2</td><td>2</td>
  <tr>
</table>

Each elements removed give points to the player.

Languages & Libraries 
--------------------
Project written in C++ (100%)

Using SDL, SDL_image, SDL_TTF & SDL_gfx libraries

Use Makefile to compile.

Progress
--------

**Prototype version, main goals (100%)**
- [x] gravitational matrix
- [x] grid class & main methods
- [x] check grid behavior
- [x] game engine
- [x] screen classes (state pattern)
- [x] gridmode classes (strategy pattern)
- [x] element classes (decorator pattern)
- [x] engine singleton

**Final version, let there be light (100%)**
- [x] full graphics
- [x] gui
- [x] elements animation
