# 🌌 The DSA Dungeon — Survival Guide (C Edition)

<div align="center">

![Header](https://capsule-render.vercel.app/api?type=waving\&color=0:0f172a,100:0ea5a4\&height=220\&section=header\&text=🗡️%20THE%20DSA%20DUNGEON\&fontSize=48\&fontColor=ffffff\&animation=twinkling\&desc=C%20Edition%20•%20Algorithms%20&%20Data%20Structures%20Made%20Tactical\&descSize=16)

[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=JetBrains+Mono\&size=22\&duration=2500\&color=0ea5a4\&center=true\&lines=Conquer+algorithms+%7C+Master+data+structures+%7C+Ship+ready+C+implementations)](https://git.io/typing-svg)

![C](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge\&logo=c\&logoColor=white)
![Algorithms](https://img.shields.io/badge/Algorithms-DSA-F59E0B?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Toolbox%20Ready-10B981?style=for-the-badge) <img src="https://komarev.com/ghpvc/?username=prak05&color=0ea5a4&style=flat-square&label=Project+Views" alt="Project Views" />

</div>

---

## 🔥 What is this?

**The DSA Dungeon — Survival Guide (C Edition)** is a battle-tested repository of classic and advanced data structures & algorithms implemented in plain **C**, curated for learners who want readable, exam-ready, and competition-ready solutions. Each folder contains explanation, implementation, complexity notes, and sample input/output so you can learn fast and apply immediately.

Ideal for:

* Students preparing for exams, labs, or interviews
* Competitors prepping for coding contests (C-specific)
* Teachers and TAs wanting reference implementations

---

## ⚔️ Highlights

* ✅ Clear, compact C implementations (formatted according to the repo convention)
* ✅ Algorithm explanation + time & space complexities
* ✅ Example inputs, outputs and small test harnesses
* ✅ Topic map: Arrays → Linked Lists → Trees → Graphs → Greedy → DP → Advanced DS
* ✅ Helpful diagrams (mermaid) and a study roadmap

---

## 🧭 Repo Live Stats

<div align="center">

<img height="140em" src="https://github-readme-stats.vercel.app/api?username=prak05&show_icons=true&theme=radical&hide_border=true&count_private=true"/>
<img height="140em" src="https://github-readme-stats.vercel.app/api/top-langs/?username=prak05&layout=compact&theme=radical&hide_border=true"/>

</div>

---

## 🗂️ Project Structure (overview)

```plaintext
The-DSA-Dungeon-Survival-Guide-C-Edition/
├── 00-README/                     # This guide + contribution notes
├── 01-arrays/                     # Arrays + two-pointers + sliding window
├── 02-strings/                    # String algorithms & pattern matching
├── 03-linked-lists/               # SLL, DLL, circular lists + utilities
├── 04-stacks-queues/              # Stack, Queue, Deque, monotonic stacks
├── 05-trees/                      # Binary trees, BST, segment tree, trie
├── 06-graphs/                     # DFS, BFS, Dijkstra, MSTs, topological sort
├── 07-sorting-searching/          # Quick/merge/heap + order statistics
├── 08-dp/                         # DP problems with tabulation & memoization
├── 09-advanced/                   # Fenwick, Disjoint Set Union, Suffix Array
├── tests/                         # Small driver programs and testcases
├── docs/                          # Explanations, mermaid diagrams, cheat-sheets
└── LICENSE
```

---

## 🧩 Example: Short C implementation (style note — code without indentation)

Sample — iterative binary search (no indentation per repo style preference):

```c
#include <stdio.h>
int binary_search(int a[], int n, int key){
int l=0,r=n-1;
while(l<=r){
int m=l+(r-l)/2;
if(a[m]==key) return m;
if(a[m]<key) l=m+1;
else r=m-1;
}
return -1;
}
int main(){
int arr[]={1,3,5,7,9,11};
int n=6;
int key=7;
int idx=binary_search(arr,n,key);
if(idx!=-1) printf("Found at index %d\n",idx);
else printf("Not found\n");
return 0;
}
```

---

## 🧠 Learning Map (visual)

```mermaid
graph LR
A(Arrays) --> B(Strings)
B --> C(Linked Lists)
C --> D(Stacks & Queues)
D --> E(Trees)
E --> F(Graphs)
F --> G(Advanced DS)
G --> H(Dynamic Programming)
style A fill:#0ea5a4,stroke:#064e3b,color:#fff
style H fill:#f59e0b,stroke:#92400e,color:#fff
```

---

## 🚀 Quickstart — run tests locally

```bash
# 1) Clone
git clone https://github.com/prak05/The-DSA-Dungeon-Survival-Guide-C-Edition-.git
cd The-DSA-Dungeon-Survival-Guide-C-Edition-

# 2) Compile an example (move into chosen folder)
gcc tests/binary_search_test.c -o bin_search && ./bin_search

# 3) Run test suite (simple)
for f in tests/*.c; do gcc $f -o tmp && ./tmp; done
```

> Tip: Each folder includes a `README.md` with problem statement, complexity analysis, and testcases.

---

## 📚 How files are organized in each topic

Each topic folder contains:

* `problem-name.c` — C source (compile-ready)
* `problem-name.md` — Explanation, complexity, and examples
* `input.txt` / `output.txt` — sample I/O for quick tests
* `Makefile` (optional) — build targets for that topic

---

## ✅ Style & Conventions

* C99-compatible code where possible.
* No deep pointer obfuscation — readability prioritized.
* Short header comments listing complexity: `// O(n log n) time | O(1) aux`.
* Example inputs printed as shown in `tests/` so instructors can demo quickly.
* If you submit PRs: keep code style consistent (variable names, no deep nesting).

---

## 🛠️ Tools & Tech

* Language: C (gcc / clang)
* Test runner: simple shell / Makefile
* Documentation: Markdown + mermaid diagrams
* CI: optional GitHub Actions (suggested workflow included in `docs/ci/`)

---

## 🎯 Roadmap & Wishlist

* [ ] Add interactive test harness (input generator + validator)
* [ ] Add performance benchmarks & memory profiles
* [ ] Add video walkthroughs for top 50 problems
* [ ] Create a practice playlist (beginner → advanced) with tags & difficulty scores
* [ ] Add GitHub Actions CI to compile all C files on push

---

## 🤝 Contributing

We welcome bugfixes, new problems, better explanations, and testcases.

1. Fork the repo
2. Create a topic branch: `git checkout -b feat/merge-sort-c`
3. Add code + `problem-name.md` (include complexity & sample I/O)
4. Run tests locally (`gcc`, run `tests/*.c`)
5. Open a Pull Request with a clear description & sample I/O

Please follow the coding style (brief header, complexity tag, and no extra indentation in code files).

---

## 🧾 License

This project uses the **MIT License** — see `LICENSE` for details. Feel free to reuse, adapt, and contribute back.

---

## 👤 Author

**Prakhar Sharma** — *DSA Practitioner & C Enthusiast*
[![GitHub](https://img.shields.io/badge/GitHub-prak05-black?style=for-the-badge\&logo=github)](https://github.com/prak05) [![LinkedIn](https://img.shields.io/badge/LinkedIn-prak05--btech-blue?style=for-the-badge\&logo=linkedin)](https://linkedin.com/in/prak05-btech)

---

<div align="center">

### ⭐ If this repo helped you level up, please give it a star and share your PRs — survive the dungeon and pass it on! 🛡️

</div>
