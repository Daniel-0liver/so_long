# so_long
This is a project for the 42 Lisbon School of a 2D game developed in C; it was a lot of fun to create a game where I did almost everything from scratch.


![so_long_animation](https://user-images.githubusercontent.com/84101904/190930463-727af433-7ad1-4a89-8a0c-efac93853493.gif)

<h2 align="center" id="requirements"> Requirements </h2>

<p  align="center"> :warning: The project must be written in accordance with the <a href="https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf" target="_blank">Norm</a> </p>
The Norm  is a programming standard that defines a set of rules to follow when writing code at 42. It applies to all C projects within the Common Core by default, and
to any project where it's specified. These are some of them:

    Each function must be maximum 25 lines, not counting the function's own curly brackets.
    
    Each line must be at most 80 columns wide, comments included.
    
    A function can take 4 named parameters maximum.
    
    You can't declare more than 5 variables per function.
    
    You're not allowed to use: for , do...while , switch , case ,  goto  ,
    ternary operators such as `?' and VLAs - Variable Length Arrays.
  The norminette (as we call the norm at 42) is in python and open source.
  
  Its repository is available at https://github.com/42School/norminette.
  
### How to play
---
###### Maps
The game is able to play any map you want as long as it follow some specific rules:
* The map has to be a ``.ber`` file.
* It can only contain some of the following characters:

| Character | Object |
| - | - |
| 1 | Wall. |
| 0 | Empty space. |
| C | Collectable. |
| E | Exit. |
| P | Player starting position. |
| T | Trap. |

* The map must be a rectangle surrounded by walls ‘1’.
* It must have at least one exit ‘E’ and one collectable ‘C’. And only one player ‘P’.

See some examples in the ``map_files`` folder of this project.

