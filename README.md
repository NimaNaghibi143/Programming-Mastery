# Programming-Mastery

A shared repo where developers with different tech stacks, backgrounds, and goals gather to solve programming problems across various fields. Each contributor works through problems in their own language, documents their approach, and shares what they learn along the way.

The goal is simple: work through the problem yourself before reaching for a quick answer and develop critical thinking skills.

## Repository structure

> Please give sufficient attention to the proposed repo structure. This might seem unnecessary or bureaucratic, but in hindsight, it is a perfect practice of discipline, proper documentation, and teamwork. Thus, don't overlook this practice, pretty please!

The repo is organized by programming language. Each language directory holds **one folder per problem or project**.

```
Programming-Mastery/
├── Python/
├── C/
├── C++/
├── bash/
├── Go/
└── C#/
```

Within a language directory:

- `README.md` — list of problem names with links to each project
- `<problem-name>/` — folder with source code and its own `README.md`

Problem folders shall include as many files as required.

## Adding a new problem

1. **Choose or create a language directory** — use an existing top-level folder (`Python`, `C`, `C++`, `bash`, `Go`, `C#`) or add a new one if your language is not listed yet.

2. **Create a problem folder** — use a short, descriptive name (e.g. `Unit-Converter`, `binary-tree`). Group related problems in a subfolder if it helps (see `bash/network-tools/`).

3. **Add a problem README** — describe the problem, your approach, and how to build and run the code. Look at existing entries such as `C/binary-tree/README.md` or `Python/Monopolistic-Theater/README.md` for reference.

4. **Add your source code** — keep the solution self-contained inside the problem folder. Make sure to use proper and standard Git practices. Avoid adding 10,000 lines of code in one commit. Push your commits regularly so that other contributors can see what you do. Use a standard commit message format, or at least keep it informative.

5. **Update the language README** — add a link to your new problem under the "List of Problems" section in that language's `README.md`.
