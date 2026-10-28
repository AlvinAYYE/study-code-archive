"""逐檔編譯並執行有 main() 的 C 題解；不需要額外套件。

用法：python verify.py [題解檔案 ...]
不指定檔案時，驗證 easy/、medium/、hard/ 的精選題。
"""

from __future__ import annotations

import shutil
import subprocess
import sys
import tempfile
from pathlib import Path


ROOT = Path(__file__).resolve().parent


def visual_studio_setup() -> Path | None:
    installer = Path(r"C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe")
    if not installer.exists():
        return None
    result = subprocess.run(
        [str(installer), "-latest", "-products", "*", "-property", "installationPath"],
        capture_output=True,
        text=True,
        encoding="utf-8",
        check=False,
    )
    if result.returncode != 0 or not result.stdout.strip():
        return None
    setup = Path(result.stdout.strip()) / "VC" / "Auxiliary" / "Build" / "vcvars64.bat"
    return setup if setup.exists() else None


def compile_and_run(source: Path, temp: Path, setup: Path | None) -> tuple[bool, str]:
    executable = temp / (source.stem + (".exe" if sys.platform == "win32" else ""))
    if shutil.which("gcc"):
        command = ["gcc", "-std=c11", "-O2", str(source), "-o", str(executable)]
    elif shutil.which("clang"):
        command = ["clang", "-std=c11", "-O2", str(source), "-o", str(executable)]
    elif setup is not None:
        batch = temp / "compile.cmd"
        batch.write_text(
            f'@echo off\ncall "{setup}" >nul\n'
            f'cl /nologo /std:c17 /utf-8 /Fe:"{executable}" "{source}"\n',
            encoding="utf-8",
        )
        command = ["cmd", "/c", str(batch)]
    else:
        return False, "找不到 gcc、clang 或 Visual Studio C 編譯器"

    built = subprocess.run(command, cwd=temp, capture_output=True, text=True, errors="replace")
    if built.returncode != 0:
        return False, (built.stdout + built.stderr).strip()
    ran = subprocess.run([str(executable)], cwd=temp, capture_output=True, text=True, errors="replace")
    return ran.returncode == 0, (ran.stdout + ran.stderr).strip()


def main() -> int:
    if len(sys.argv) > 1:
        sources = [Path(name).resolve() for name in sys.argv[1:]]
    else:
        sources = sorted(source for folder in ("easy", "medium", "hard") for source in (ROOT / folder).glob("*.c"))
    if not sources:
        print("找不到 C 題解。")
        return 1

    setup = visual_studio_setup() if sys.platform == "win32" else None
    failed = 0
    for source in sources:
        if not source.is_file():
            print(f"FAIL {source}: 檔案不存在")
            failed += 1
            continue
        with tempfile.TemporaryDirectory(prefix="leetcode-c-") as directory:
            ok, output = compile_and_run(source, Path(directory), setup)
        print(f"{'PASS' if ok else 'FAIL'} {source.relative_to(ROOT) if source.is_relative_to(ROOT) else source}")
        if not ok:
            failed += 1
            print(output)
    print(f"Summary: {len(sources) - failed}/{len(sources)} passed")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
