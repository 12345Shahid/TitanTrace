# TitanTrace: Deep Recursive File Analyzer

TitanTrace is a high-performance command-line utility written in C for deep recursive analysis of directory structures. It provides insights into storage consumption and code volume by traversing entire file systems efficiently.

## Features

- **Recursive Traversal**: Scans all subdirectories starting from a specified base path.
- **Size Aggregation**: Calculates the total disk space occupied by all files within the directory tree.
- **Line Count Analysis**: Aggregates the total number of lines across all text-based files.
- **Top File Tracking**: Identifies and reports the top 5 largest files encountered during the scan.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Make (optional, but recommended)

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/12345Shahid/TitanTrace.git
   cd TitanTrace
   ```

2. Compile the project:
   ```bash
   make
   ```

### Usage

Run TitanTrace by providing the target directory as an argument:

```bash
./titantrace /path/to/directory
```

### Example Output

```text
--- TitanTrace Report ---
Mot Size: 10485760 bytes
Mot Lines: 125430

Boro Files:
1. /home/user/data/large_dataset.csv (5242880 bytes)
2. /home/user/data/backup_log.txt (2140000 bytes)
3. /home/user/data/process_info.json (1024000 bytes)
4. /home/user/data/app_binary (800000 bytes)
5. /home/user/data/temp_cache.tmp (500000 bytes)
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.
