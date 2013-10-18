Swrid
=====

*A kind of mixture between Tetris & Jewel*

Project by **David Perrai** & **Brice Thomas**

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

Then, we filled randomly the first five rows from the bottom with four types of element :
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
    <td>3</td><td>2</td><td>1</td><td>3</td><td>4</td><td>2</td><td>4</td><td>1</td><td>4</td><td>3</td><td>4</td><td>1</td>
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

Progress
--------

- [x] gravitational matrix
- [x] grid class & main methods
- [ ] check grid behavior (strange suppression and push up sometimes)
- [x] game engine
- [x] screen classes (state pattern)
- [x] gridmode classes (strategy pattern)
- [ ] thrid design pattern (decorator on elements ?)
- [ ] fourth design pattern (singleton on grid ?)
