const fs = require("fs");
const lines = fs.readFileSync("input", "utf-8").split("\r\n").map(x => x.split(" ").map(Number));

function check_sequence_diff(history) {
    for (let item of history) {
        if (item !== 0) {
            return false;
        }
    }
    return true;
}

function compute_next_hist(hist) {
    var next_hist = [];
    for (let i = 1; i < hist.length; i++) {
        next_hist.push(hist[i] - hist[i - 1]);
    }
    return next_hist;
}

var part2 = 0;

for (let i = 0; i < lines.length; i++) {
    var histories = [];
    histories.push(compute_next_hist(lines[i]));
    while (!check_sequence_diff(histories[histories.length - 1])) {
        histories.push(compute_next_hist(histories[histories.length - 1]));
    }

    var temp = histories[histories.length - 1][0];

    for (let j = histories.length - 2; j >= 0; j--) {
        temp = -1 * (temp - histories[j][0]);
    }

    part2 += -1 * (temp - lines[i][0]);
}

console.log(part2);

/*
var part1 = 0;

for (let i = 0; i < lines.length; i++) {
    var histories = [];
    part1 += lines[i][lines[i].length - 1];
    histories.push(compute_next_hist(lines[i]));
    while (!check_sequence_diff(histories[histories.length - 1])) {
        let subarray = histories[histories.length - 1]
        part1 += subarray[subarray.length - 1];
        histories.push(compute_next_hist(histories[histories.length - 1]));
    }
}

console.log(part1);
*/