# TL;DR

Personal [Miryoku](https://github.com/manna-harbour/miryoku/tree/master/docs/reference)-ish _(6 columns, 3 rows, 3 thumb keys)_ layout configuration for the [Hallie](https://splitted.space/en/keyboard/wireless-low-profile-split-keyboard-hallie) split keyboard.

![Layout](https://raw.githubusercontent.com/kolibabchuk/hallie-miryoku/assets/keymap.svg)

> The layout image above is regenerated on every push to `main` and stored on the orphan `assets` branch. The first successful CI run populates it.

## Why this repo exists

Previously, running Miryoku on a Hallie required maintaining forks of both `zmkfirmware/zmk` and `manna-harbour/miryoku_zmk`. Rebasing was painful and slowed ZMK upgrades to a crawl.

This repo replaces forks with an **overlay on top of upstream**:

| Piece | Source | Role |
|---|---|---|
| ZMK firmware | `zmkfirmware/zmk` (upstream) | Kernel, BLE, core behaviors |
| Miryoku core | `manna-harbour/miryoku_zmk` (upstream) | Layer machinery, alpha layouts |
| Hallie board | `SplittedSpace/zmk-keyboards-splittedspace` | Device tree, defconfig, board wiring |
| Hallie features | `SplittedSpace/zmk-feature-splittedspace` | LED widget engine, `&ind` behavior, YBM encoder driver |
| **This repo** | — | Overlay files + per-layer overrides + CI |

The build pipeline clones the four upstream repos at **pinned SHAs/tags**, copies this repo's overlay files on top of the Miryoku checkout, then runs `west build`. No forks to rebase. Pins are overridable per-run via `workflow_dispatch` inputs.

## Repository structure

```
hallie-miryoku/
  .github/workflows/build.yml    # Build + keymap-drawer pipeline
  overlay/
    config/
      hallie.keymap              # Entry point — three #include lines
    miryoku/
      custom_config.h            # Include <behaviors/indicators.dtsi>, layer-mapping
                                 #   aliases, MIRYOKU_LAYER_{NAV,MOUSE,MEDIA} overrides
      miryoku.dtsi               # Core keymap generator (3-arg MIRYOKU_X)
      miryoku_double_tap_guard.dtsi
      miryoku_behaviors.dtsi     # urob-style u_mt / u_lt + Globe / Hyper / input-switch
      miryoku_behaviors.h        # U_MT / U_LT convenience macros
      miryoku_babel/
        miryoku_layer_list.h     # 10 layers with per-layer encoder bindings
      mapping/42/
        hallie.h                 # 42-key physical layout: outer columns per layer
  assets/
    keymap-drawer/
      layout-override.json       # Physical key geometry for keymap-drawer
```

## Build

Fork the repo on GitHub, then either push any commit or run **Actions → Build → Run workflow** manually. GitHub Actions will produce `hallie_left.uf2` and `hallie_right.uf2` as run artifacts — download them from the completed run and flash per standard ZMK instructions.

What the workflow (`.github/workflows/build.yml`) does:

1. Clones `manna-harbour/miryoku_zmk` at pinned commit `559aa4be…`
2. Overlays this repo's `overlay/` files onto the Miryoku checkout (replaces specific files, adds new ones like `mapping/42/hallie.h`)
3. Prepends config defines to `custom_config.h` (`MIRYOKU_KEYBOARD_HALLIE`, `MIRYOKU_NAV_INVERTEDT`, `MIRYOKU_CLIPBOARD_MAC`)
4. Generates per-board `.conf` overrides (Studio off, pointing on, 1 h idle sleep, Apple VID/PID on left half only, full HID consumer usage map)
5. Clones `zmkfirmware/zmk@v0.3.0` and the two SplittedSpace vendor modules at pinned SHAs
6. Runs `west init`, `west update`, `west build` for each half (matrix over `hallie_left`, `hallie_right`)
7. Uploads the UF2s as run artifacts

On pushes to `main`, a second job parses the preprocessed keymap DTS with [keymap-drawer](https://github.com/caksoylar/keymap-drawer) and commits the resulting SVG to the orphan `assets` branch — that's what renders at the top of this README.

All pins are overridable per-run via the workflow's `workflow_dispatch` inputs — handy when testing against newer ZMK / Miryoku before committing to a pin bump.

## Layout overview

### Outer column keys — BASE / EXTRA / TAP

| Position | Tap | Hold | Double-tap |
|---|---|---|---|
| Left top | `\` | Globe | go to BASE |
| Left middle | `]` | Hyper | — |
| Left bottom | input switch (Ctrl+Space) | Left Shift | — |
| Right top | `[` | Globe | — |
| Right middle | `'` | Hyper | — |
| Right bottom | `/` | Right Shift | — |

### Outer column keys — function layers (NAV, MOUSE, MEDIA, NUM, SYM, FUN)

| Position | Key |
|---|---|
| Left top | Mission Control Apps |
| Left middle | Mission Control Windows |
| Left bottom | Spotlight |
| Right top | Escape |
| Right middle | Hyper |
| Right bottom | Globe |

### BUTTON layer

All six outer columns: bootloader entry (`U_BOOT`).

### Inner-index column overrides — K04 / K14 / K24

These are the "stretch" columns the index finger reaches for. Miryoku's upstream leaves them empty on most function layers; this repo puts them to use via `MIRYOKU_LAYER_*` overrides in `overlay/miryoku/custom_config.h`.

| Layer | K04 (row 0, left index) | K14 (row 1, left index) | K24 (row 2, left index) | K05 (row 0, right index) | K15 (row 1, right index) |
|---|---|---|---|---|---|
| NAV | PrintScreen | ScrollLock | Context Menu | PageUp | PageDn |
| MOUSE | PrintScreen | ScrollLock | Context Menu | PageUp | PageDn |
| MEDIA | `&ind BAT_ST` (battery LED ramp) | `&ind IND_ON` (indicator toggle) | System Power | — | — |

Everything else on these layers follows upstream Miryoku with `MIRYOKU_NAV_INVERTEDT` selected.

### Encoder bindings

| Layer | Left encoder | Right encoder |
|---|---|---|
| BASE, EXTRA, TAP, BUTTON | Left / Right | Up / Down |
| NAV | Up / Down | Left / Right |
| MOUSE | Left / Right | Up / Down |
| MEDIA | Brightness Down / Up | Volume Up / Down |
| NUM, SYM, FUN | Left / Right | Up / Down |

### Custom behaviors

Defined in `overlay/miryoku/miryoku_behaviors.dtsi`.

- **`u_mt`, `u_lt`, `mt_input_switch`** — mod-tap, layer-tap, and input-switch-tap, all tuned urob-style: `flavor = balanced`, `tapping-term-ms = 280`, `quick-tap-ms = 175`, `require-prior-idle-ms = 150`, `hold-trigger-on-release`. Near-zero home-row-mod misfires during rolling typing while keeping deliberate holds instant. Bilateral (`hold-trigger-key-positions`) is deliberately omitted — it would require per-hand HRM behaviors and overriding the BASE/EXTRA/TAP alphas.
- **`td_bslh_globe_base`** — tap-dance on left-top outer: tap `\` (with Globe as hold), double-tap jumps to BASE.
- **`input_switch`** — macro for Ctrl+Space; cycles macOS input sources.
- **`&ind`** — battery / indicator behavior from `zmk-feature-splittedspace`. Argument `BAT_ST` triggers the LED battery ramp animation; `IND_ON` toggles indicators globally. Bound on the MEDIA layer.

## Customization

### Miryoku options — alphas, nav, clipboard

Edit the "Assemble config defines" step in `build.yml`:

```yaml
echo '#define MIRYOKU_NAV_INVERTEDT' >> "$tmpfile"
echo '#define MIRYOKU_CLIPBOARD_MAC' >> "$tmpfile"
```

To switch alphas: `echo '#define MIRYOKU_ALPHAS_QWERTY' >> "$tmpfile"` (defaults to Colemak-DH; EXTRA defaults to QWERTY). See the [Miryoku reference](https://github.com/manna-harbour/miryoku/tree/master/docs/reference) for all options.

### Outer column keys

Edit `overlay/miryoku/mapping/42/hallie.h`. Each layer has its own mapping macro (`MIRYOKU_LAYOUTMAPPING_HALLIE`, `MIRYOKU_LAYOUTMAPPING_NAV`, `MIRYOKU_LAYOUTMAPPING_NUM`, etc.).

### Inner layer content — K04 / K14 / K24 and cluster order

Edit `overlay/miryoku/custom_config.h` where `MIRYOKU_LAYER_NAV`, `MIRYOKU_LAYER_MOUSE`, and `MIRYOKU_LAYER_MEDIA` are defined. Each macro is the full 40-element layer body; the upstream `#if !defined(MIRYOKU_LAYER_*)` guards let our definitions win. Leave these alone if you want the pure upstream Miryoku behavior.

### Encoder bindings

Edit `overlay/miryoku/miryoku_babel/miryoku_layer_list.h`. Each line's third argument carries the `sensor-bindings` for that layer:

```c
MIRYOKU_X(BASE, "Base", sensor-bindings = <&inc_dec_kp LEFT RIGHT &inc_dec_kp UP DOWN>;)
```

First `&inc_dec_kp` pair is the left encoder; second is the right encoder.

### Custom behaviors

Edit `overlay/miryoku/miryoku_behaviors.dtsi` for devicetree behaviors (hold-tap tuning, tap-dances, macros) and `overlay/miryoku/miryoku_behaviors.h` for convenience macros (`U_MT`, `U_LT`).

### Kconfig overrides

Generated at build time in the workflow:

**Both halves:**
- `CONFIG_ZMK_STUDIO=n` — ZMK Studio disabled (all changes require rebuild + flash)
- `CONFIG_ZMK_POINTING=y` — pointing device support compiled in
- `CONFIG_ZMK_IDLE_SLEEP_TIMEOUT=3600000` — 1 hour sleep timeout
- `CONFIG_ZMK_HID_CONSUMER_REPORT_USAGES_FULL=y` — full consumer usage table (needed for `C_AC_DESKTOP_SHOW_ALL_APPLICATIONS` etc.)

**Left half only:**
- `CONFIG_USB_DEVICE_VID=0x05AC` / `CONFIG_USB_DEVICE_PID=0x0267` — Apple USB identifiers for Globe key support on macOS

### Dependency pinning

The build image (`zmkfirmware/zmk-build-arm`) is pinned by SHA256 digest in `build.yml`. External repos (ZMK, Miryoku, SplittedSpace modules) are pinned by tag or commit SHA. To re-float: change the `default:` values under `workflow_dispatch.inputs`, or override per-run.

## Further reading

- [Hallie usage guide](https://splitted.space/instruktsiia-z-vykorystannia-bezdrotovoi-split-klaviatury-hallie) from Splitted Space — covers charging, pairing, and general hardware usage of the keyboard itself. _Heads up: Ukrainian language only._
