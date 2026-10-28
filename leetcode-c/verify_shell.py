"""在 Git Bash 中用官方例子格式驗證 Shell 題解。"""

from __future__ import annotations

import shutil
import subprocess
import sys
import tempfile
from pathlib import Path


ROOT = Path(__file__).resolve().parent
BASH = Path(r"C:\Program Files\Git\bin\bash.exe")
if not BASH.exists():
    found = shutil.which("bash")
    BASH = Path(found) if found else BASH

CASES = [
    (
        "0192_word-frequency.sh", "words.txt",
        "the day is sunny the the\nthe sunny is is\n",
        "the 4\nis 3\nsunny 2\nday 1\n",
    ),
    (
        "0193_valid-phone-numbers.sh", "file.txt",
        "987-123-4567\n123 456 7890\n(123) 456-7890\n",
        "987-123-4567\n(123) 456-7890\n",
    ),
    (
        "0194_transpose-file.sh", "file.txt",
        "name age\nalice 21\nryan 30\n",
        "name alice ryan\nage 21 30\n",
    ),
    (
        "0195_tenth-line.sh", "file.txt",
        "".join(f"Line {i}\n" for i in range(1, 11)),
        "Line 10\n",
    ),
    (
        "0195_tenth-line.sh", "file.txt",
        "".join(f"Line {i}\n" for i in range(1, 10)),
        "",
    ),
]


def main() -> int:
    sys.stdout.reconfigure(encoding="utf-8")
    if not BASH.exists():
        print("找不到 Git Bash，無法執行 Shell 範例。")
        return 1

    failed = 0
    for filename, input_name, input_text, expected in CASES:
        with tempfile.TemporaryDirectory(prefix="leetcode-shell-") as directory:
            work = Path(directory)
            source = ROOT / "shell" / filename
            script = work / filename
            script.write_text(source.read_text(encoding="utf-8"), encoding="utf-8")
            (work / input_name).write_text(input_text, encoding="utf-8")
            result = subprocess.run(
                [str(BASH), str(script)], cwd=work, capture_output=True, text=True, errors="replace"
            )
        ok = result.returncode == 0 and result.stdout == expected
        print(f"{'PASS' if ok else 'FAIL'} {filename}")
        if not ok:
            print(f"  expected: {expected!r}\n  actual:   {result.stdout!r}\n  stderr:   {result.stderr!r}")
            failed += 1
    print(f"Summary: {len(CASES) - failed}/{len(CASES)} passed")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
