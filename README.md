# approximate-pi

A simple approximation of the circle constant pi using a "[monte carlo](https://en.wikipedia.org/wiki/Monte_Carlo_algorithm)" method.

# monte calo algorithm
My implementaion is simple I use an modified verion of `rand()`,just that I get an double within an range, to drop my points.
My calculation in `approximatePI()` is from the wiki page:

`(pointsInCircle * pointsTotal) / 4`

# not my stuff:

The `fRand()` function is from stackoverflow user [Frank](https://stackoverflow.com/users/60628/frank) posted in https://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c

I use the [BigFloat](https://github.com/Mariotti94/BigFloat) - Arbitrary-Precision Float Arithmetic Library by [Gianfranco Mariotti](https://github.com/Mariotti94)

# idea

I got the idea to do an c++ implementation of an aproximation of pi because of an [video](https://www.youtube.com/watch?v=5cNnf_7e92Q) by [CodingTrain](https://github.com/CodingTrain).
I wrote some of the code simular to the one in video, so that is also not quite my stuff.
