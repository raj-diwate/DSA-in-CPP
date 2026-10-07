from pathlib import Path
from datetime import datetime, timezone
from html import escape
import re


# =========================================================
# CONFIGURATION
# =========================================================

ROOT = Path(__file__).resolve().parent.parent
OUTPUT = ROOT / "assets" / "dsa-dashboard.svg"

IGNORED_DIRECTORIES = {
    ".git",
    ".github",
    "scripts",
    "assets",
}

DIFFICULTIES = ("easy", "medium", "hard")


# =========================================================
# HELPERS
# =========================================================

def clean(value):
    """Normalize text for comparison."""
    return re.sub(r"\s+", " ", value.strip()).lower()


def parse_markdown_tables(content):
    """
    Find Markdown tables containing a Difficulty column.

    This intentionally does not depend on exact spacing.
    """

    lines = content.splitlines()
    rows = []

    for i, line in enumerate(lines):

        if "|" not in line:
            continue

        header = [
            clean(x)
            for x in line.strip().strip("|").split("|")
        ]

        if "difficulty" not in header:
            continue

        difficulty_index = header.index("difficulty")

        # Markdown table separator should normally be next line
        if i + 1 >= len(lines):
            continue

        separator = lines[i + 1].strip()

        if "|" not in separator:
            continue

        # Read rows after separator
        j = i + 2

        while j < len(lines):

            row = lines[j].strip()

            if not row.startswith("|"):
                break

            columns = [
                x.strip()
                for x in row.strip().strip("|").split("|")
            ]

            if difficulty_index < len(columns):

                difficulty = clean(columns[difficulty_index])

                if difficulty in DIFFICULTIES:
                    rows.append(difficulty)

            j += 1

    return rows


# =========================================================
# SCAN ALL TOPIC READMES
# =========================================================

topic_data = {}

for readme in ROOT.rglob("README.md"):

    relative_parts = readme.relative_to(ROOT).parts

    # Ignore repository README
    if readme == ROOT / "README.md":
        continue

    # Ignore utility/generated directories
    if any(part in IGNORED_DIRECTORIES for part in relative_parts):
        continue

    topic = readme.parent.name

    try:
        content = readme.read_text(encoding="utf-8")
    except Exception as error:
        print(f"Warning: Could not read {readme}: {error}")
        continue

    difficulties = parse_markdown_tables(content)

    if not difficulties:
        continue

    topic_data[topic] = {
        "easy": difficulties.count("easy"),
        "medium": difficulties.count("medium"),
        "hard": difficulties.count("hard"),
    }


# =========================================================
# OVERALL STATISTICS
# =========================================================

easy = sum(topic["easy"] for topic in topic_data.values())
medium = sum(topic["medium"] for topic in topic_data.values())
hard = sum(topic["hard"] for topic in topic_data.values())

total = easy + medium + hard


def percentage(value):
    if total == 0:
        return 0.0

    return value / total * 100


easy_percentage = percentage(easy)
medium_percentage = percentage(medium)
hard_percentage = percentage(hard)


# =========================================================
# TOPIC STATISTICS
# =========================================================

for topic, data in topic_data.items():

    data["total"] = (
        data["easy"]
        + data["medium"]
        + data["hard"]
    )

topics = sorted(
    topic_data.items(),
    key=lambda item: item[1]["total"],
    reverse=True
)

max_topic_total = max(
    [data["total"] for _, data in topics],
    default=1
)


# =========================================================
# SVG CONFIGURATION
# =========================================================

WIDTH = 1100
HEIGHT = 1050

BACKGROUND = "#111111"
PANEL = "#1b1b1b"
PANEL_LIGHT = "#222222"
BORDER = "#2c2c2c"

TEXT = "#ffffff"
TEXT_SECONDARY = "#a0a0a0"
TEXT_MUTED = "#666666"

EASY_COLOR = "#22c55e"
MEDIUM_COLOR = "#f59e0b"
HARD_COLOR = "#ef4444"
ACCENT = "#00bfa5"


# =========================================================
# SVG HELPERS
# =========================================================

svg = []


def rect(
    x,
    y,
    width,
    height,
    fill,
    radius=16,
    stroke="none",
    stroke_width=0,
):
    svg.append(
        f'<rect x="{x}" y="{y}" '
        f'width="{width}" height="{height}" '
        f'rx="{radius}" '
        f'fill="{fill}" '
        f'stroke="{stroke}" '
        f'stroke-width="{stroke_width}"/>'
    )


def text(
    x,
    y,
    value,
    size,
    fill=TEXT,
    weight="400",
    anchor="start",
):
    svg.append(
        f'<text x="{x}" y="{y}" '
        f'font-family="Inter, Segoe UI, Arial, sans-serif" '
        f'font-size="{size}px" '
        f'font-weight="{weight}" '
        f'fill="{fill}" '
        f'text-anchor="{anchor}">'
        f'{escape(str(value))}'
        f'</text>'
    )


# =========================================================
# SVG START
# =========================================================

svg.append(
    f'<svg xmlns="http://www.w3.org/2000/svg" '
    f'width="{WIDTH}" height="{HEIGHT}" '
    f'viewBox="0 0 {WIDTH} {HEIGHT}">'
)

# Background
svg.append(
    f'<rect width="{WIDTH}" height="{HEIGHT}" '
    f'rx="28" fill="{BACKGROUND}"/>'
)

# Outer border
svg.append(
    f'<rect x="1" y="1" '
    f'width="{WIDTH - 2}" height="{HEIGHT - 2}" '
    f'rx="28" fill="none" '
    f'stroke="{BORDER}" stroke-width="2"/>'
)


# =========================================================
# HEADER
# =========================================================

text(
    WIDTH / 2,
    55,
    "DSA IN C++",
    30,
    TEXT,
    "700",
    "middle",
)

text(
    WIDTH / 2,
    82,
    "PROGRESS DASHBOARD",
    14,
    TEXT_SECONDARY,
    "600",
    "middle",
)


# =========================================================
# MAIN SOLVED CIRCLE
# =========================================================

cx = WIDTH / 2
cy = 200

radius = 92

circumference = 2 * 3.14159265359 * radius

# Circle background
svg.append(
    f'<circle cx="{cx}" cy="{cy}" r="{radius}" '
    f'fill="none" stroke="#292929" stroke-width="14"/>'
)

# Progress ring
if total > 0:

    svg.append(
        f'<circle cx="{cx}" cy="{cy}" r="{radius}" '
        f'fill="none" stroke="{ACCENT}" stroke-width="14" '
        f'stroke-linecap="round" '
        f'stroke-dasharray="{circumference} {circumference}" '
        f'transform="rotate(-90 {cx} {cy})"/>'
    )

text(
    cx,
    cy + 8,
    total,
    52,
    TEXT,
    "700",
    "middle",
)

text(
    cx,
    cy + 38,
    "SOLVED",
    15,
    TEXT_SECONDARY,
    "600",
    "middle",
)


# =========================================================
# DIFFICULTY CARDS
# =========================================================

cards = [
    ("EASY", easy, easy_percentage, EASY_COLOR),
    ("MEDIUM", medium, medium_percentage, MEDIUM_COLOR),
    ("HARD", hard, hard_percentage, HARD_COLOR),
]

card_width = 300
card_height = 155
card_gap = 25

cards_total_width = (
    card_width * 3
    + card_gap * 2
)

card_start_x = (
    WIDTH - cards_total_width
) / 2

card_y = 330


for index, (label, count, percent, color) in enumerate(cards):

    x = (
        card_start_x
        + index * (card_width + card_gap)
    )

    rect(
        x,
        card_y,
        card_width,
        card_height,
        PANEL,
        18,
        BORDER,
        1,
    )

    # Accent strip
    rect(
        x,
        card_y,
        card_width,
        5,
        color,
        3,
    )

    text(
        x + card_width / 2,
        card_y + 40,
        label,
        15,
        color,
        "700",
        "middle",
    )

    text(
        x + card_width / 2,
        card_y + 88,
        count,
        38,
        TEXT,
        "700",
        "middle",
    )

    text(
        x + card_width / 2,
        card_y + 120,
        f"{percent:.1f}%",
        14,
        TEXT_SECONDARY,
        "500",
        "middle",
    )


# =========================================================
# DIFFICULTY DISTRIBUTION
# =========================================================

section_y = 535

text(
    70,
    section_y,
    "DIFFICULTY DISTRIBUTION",
    19,
    TEXT,
    "700",
)

text(
    WIDTH - 70,
    section_y,
    f"{total} PROBLEMS",
    12,
    TEXT_MUTED,
    "600",
    "end",
)


bar_x = 70
bar_y = section_y + 30
bar_width = WIDTH - 140
bar_height = 24

easy_width = (
    bar_width * easy / total
    if total
    else 0
)

medium_width = (
    bar_width * medium / total
    if total
    else 0
)

hard_width = (
    bar_width * hard / total
    if total
    else 0
)


# Background
rect(
    bar_x,
    bar_y,
    bar_width,
    bar_height,
    "#292929",
    12,
)

# Easy
if easy_width > 0:
    rect(
        bar_x,
        bar_y,
        easy_width,
        bar_height,
        EASY_COLOR,
        12,
    )

# Medium
if medium_width > 0:
    rect(
        bar_x + easy_width,
        bar_y,
        medium_width,
        bar_height,
        MEDIUM_COLOR,
        0,
    )

# Hard
if hard_width > 0:
    rect(
        bar_x + easy_width + medium_width,
        bar_y,
        hard_width,
        bar_height,
        HARD_COLOR,
        0,
    )


# Legend
legend_y = bar_y + 55

legend_items = [
    ("Easy", easy, EASY_COLOR),
    ("Medium", medium, MEDIUM_COLOR),
    ("Hard", hard, HARD_COLOR),
]

legend_x = 70

for label, count, color in legend_items:

    svg.append(
        f'<circle cx="{legend_x}" cy="{legend_y - 5}" '
        f'r="6" fill="{color}"/>'
    )

    text(
        legend_x + 15,
        legend_y,
        f"{label}  {count}",
        13,
        TEXT_SECONDARY,
        "500",
    )

    legend_x += 140


# =========================================================
# TOPIC COVERAGE
# =========================================================

topic_section_y = 680

text(
    70,
    topic_section_y,
    "TOPIC COVERAGE",
    19,
    TEXT,
    "700",
)

text(
    WIDTH - 70,
    topic_section_y,
    f"{len(topic_data)} TOPICS",
    12,
    TEXT_MUTED,
    "600",
    "end",
)


topic_y = topic_section_y + 42

bar_max_width = 470


for topic, data in topics:

    count = data["total"]

    bar_width = (
        count / max_topic_total
    ) * bar_max_width

    # Topic name
    display_name = topic[:22]

    text(
        70,
        topic_y,
        display_name,
        14,
        "#dddddd",
        "500",
    )

    # Bar background
    rect(
        255,
        topic_y - 13,
        bar_max_width,
        12,
        "#292929",
        6,
    )

    # Bar
    rect(
        255,
        topic_y - 13,
        max(bar_width, 4),
        12,
        ACCENT,
        6,
    )

    # Total
    text(
        755,
        topic_y,
        count,
        14,
        TEXT,
        "700",
        "end",
    )

    # Difficulty breakdown
    breakdown = (
        f'{data["easy"]}E  '
        f'{data["medium"]}M  '
        f'{data["hard"]}H'
    )

    text(
        920,
        topic_y,
        breakdown,
        12,
        TEXT_MUTED,
        "500",
        "end",
    )

    topic_y += 40


# =========================================================
# FOOTER
# =========================================================

updated = datetime.now(
    timezone.utc
).strftime("%d %b %Y")

text(
    WIDTH / 2,
    HEIGHT - 45,
    f"Automatically generated from DSA topic README files  •  Updated {updated}",
    12,
    TEXT_MUTED,
    "500",
    "middle",
)

svg.append("</svg>")


# =========================================================
# WRITE FILE
# =========================================================

OUTPUT.parent.mkdir(
    parents=True,
    exist_ok=True,
)

OUTPUT.write_text(
    "\n".join(svg),
    encoding="utf-8",
)


# =========================================================
# CONSOLE OUTPUT
# =========================================================

print()
print("==============================================")
print("          DSA DASHBOARD GENERATED")
print("==============================================")
print(f"Total solved : {total}")
print(f"Easy         : {easy} ({easy_percentage:.1f}%)")
print(f"Medium       : {medium} ({medium_percentage:.1f}%)")
print(f"Hard         : {hard} ({hard_percentage:.1f}%)")
print(f"Topics       : {len(topic_data)}")
print("----------------------------------------------")

for topic, data in topics:
    print(
        f"{topic:<20} "
        f"{data['total']:>3} "
        f"(E:{data['easy']} "
        f"M:{data['medium']} "
        f"H:{data['hard']})"
    )

print("----------------------------------------------")
print(f"Output: {OUTPUT}")
print("==============================================")
print()