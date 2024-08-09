const express = require('express');
const { spawn } = require('child_process');
const cors = require('cors');

const app = express();

app.use(express.json());

app.use(cors());

const handleInput = (input) => {
    return new Promise((resolve, reject) => {
        const main = spawn('./main');

        main.stdin.write(input + '\n');
        main.stdin.end();

        let output = '';
        main.stdout.on('data', (data) => {
            output += data.toString();
        });

        main.on('close', (code) => {
            if (code !== 0) {
                reject(new Error(`C++ process exited with code ${code}`));
            } else {
                resolve(output.trim());
            }
        });
    });
};

app.post('/', (req, res) => {
    const number = parseInt(req.body.number);

    if (isNaN(number)) {
        return res.status(400).json({ error: 'Invalid input, please provide a number.' });
    }

    console.log(number);

    handleInput(number.toString())
        .then((data) => {
            data = data.split('\n')[2];
            res.status(200).json({ result: data });
        })
        .catch((err) => {
            res.status(500).json({ error: err.message });
        });
});

app.listen(3000, () => {
    console.log('Server is listening on port 3000');
});
