# 42 ft_select project
A robust file browser and manager in the terminal.

## About
[ft_select] is a 42 School Unix project. The goal for this project is to learn more about screen oriented programs using termcap/terminfo libraries in the C programming language. It's originally just an argument viewer in the terminal. Basically this project builds on other projects, and will be added on other projects later on.

So creating a user interface for a program that is executed in a terminal is doable. It requires that you master the programming work involved as a terminal does not do much in its “rough” mode. To see for yourself, launch the command cat without any arguments
and press any keys or a combination of keys on your keyboard...
In doing this, as long as you press alphanumeric keys, nothing special happens. However, if you press either the arrows, the esc key or the fn keys, for example, some random characters will appear... redo the same thing in your shell now. You are used to the left arrow moving the cursor to the previous column. Why do we observe such differences between cat and your shell?

Your terminal manages many things for you without you noticing, such as for instance the display of characters as you type them or the bufferisation of each line.
You will learn to configure your terminal via the "struct termios" structure as well as to use its technical capabilities, the distinguished "termcaps".

## License
[MIT](https://choosealicense.com/licenses/mit/)