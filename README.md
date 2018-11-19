# lem_in
The goal of this project is to find the quickest way to get through the farm.
- Obviously, there are some basic constraints. To be the first to arrive, ants will need
to take the shortest path (and that is not necessarily the simplest). They will also
need to avoid traffic.
- At the beginning of the game, all the ants are in the room. The goal is
to bring them to the room. Each room can
only contain one ant at a time. (except at ## start and ## end which can contain
as many ants as necessary.)
- We consider that all the ants are in the room.
- At each turn you will only display the ants that moved.
- At each turn you can move each ant only once and through a tube (the room at
the receiving end must be empty.
- display results on the standard output in the following format:

<img width="552" alt="2018-07-04 18 59 42" src="https://user-images.githubusercontent.com/33597605/42286674-72326732-7fbc-11e8-96ae-d64e8200ae1d.png">

x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,
w, o represents the rooms’ names.

- The ant farm is defined by the following links:

<img width="564" alt="2018-07-04 19 02 15" src="https://user-images.githubusercontent.com/33597605/42286850-ca2ea982-7fbc-11e8-81ff-12103bdae33e.png">

Which corresponds to the following representation:

<img width="582" alt="2018-07-04 19 02 55" src="https://user-images.githubusercontent.com/33597605/42286873-e0d59006-7fbc-11e8-8f66-e26bbab55ce7.png">

- The rooms, which are defined by: name coord_x coord_y
- The links, which are defined by: name1-name2
- All of it is broken by comments, which start with #

Breadth-first search (BFS).

# Example

To start we will assemble the program with the help of the makefile:

<img width="877" alt="2018-07-04 19 06 52" src="https://user-images.githubusercontent.com/33597605/42287053-8ee4273e-7fbd-11e8-97e5-ee9a5396eee5.png">


Create a file with rooms, links and twelve ants:

<img width="877" alt="2018-07-04 19 14 22" src="https://user-images.githubusercontent.com/33597605/42287302-7c837472-7fbe-11e8-8781-f2bd665b9972.png">

and run

<img width="874" alt="2018-07-04 19 14 58" src="https://user-images.githubusercontent.com/33597605/42287328-94b501b4-7fbe-11e8-9e11-abcbf7c32c14.png">
