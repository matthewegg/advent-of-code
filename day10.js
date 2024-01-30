const fs = require("fs");
const contents = fs.readFileSync("input", "utf-8").split("\r\n").map(x => x.split(''));
const map = new Map([
    ['|', [[1, 0], [-1, 0]]],
    ['-', [[0, 1], [0, -1]]],
    ['L', [[-1, 0], [0, 1]]],
    ['J', [[-1, 0], [0, -1]]],
    ['7', [[0, -1], [1, 0]]],
    ['F', [[0, 1], [1, 0]]],
]);

const start_x = contents.findIndex(inner_array => inner_array.includes('S'));
const start_y = contents[start_x].indexOf('S');



/*
    at start position, get a list of all valid neighbors to be searched
        one by one, search each neighbor's path completely
            check to see if the path is a cycle
                if so, append the length of teh cycle to a list
    take the maximum of the list of cycle lengths, and divide by two (and add one?) for answer to part 1
*/