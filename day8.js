function gcd(a, b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

function lcm(a, b) {
    return (a * b) / gcd(a, b);
}

const fs = require("fs");
const [directions, garbage_line, ...mapping] = fs.readFileSync("input", "utf-8").split("\r\n").map(x => x.split(" = "));
const starting_nodes = [];
var map = new Map();

for (let line of mapping) {
    const [left, right] = line[1].replace(/\(/, '').replace(/\)/, '').split(", ");
    map.set(line[0], [left, right]);
    if (line[0][2] === "A") {
        starting_nodes.push(line[0]);
    }
}

var step_counts = []
var dir = directions.toString();

for (node of starting_nodes) {
    var step_count = 0;
    var dir_num = 0;
    while (node[2] !== "Z") {
        var curr_dir = dir[dir_num % dir.length];
        switch (curr_dir) {
            case "L":
                node = map.get(node)[0];
                break;
            case "R":
                node = map.get(node)[1];
                break;
        }
        dir_num++;
        step_count++;
    }
    step_counts.push(step_count);
}

var part2 = step_counts[0];
for (count of step_counts) {
    part2 = lcm(part2, count);
}

console.log(part2);

/*
while (curr_node !== "ZZZ") {
    var curr_dir = dir[dir_num % dir.length];
    switch (curr_dir) {
        case "L":
            curr_node = map.get(curr_node)[0];
            break;
        case "R":
            curr_node = map.get(curr_node)[1];
            break;
    }
    dir_num++;
    part1++;
}

console.log(part1);
*/