// See the LICENSE file for copyright and license details.

#define MODIFIER Mod4Mask

static const int lockfullscreen = 1;
static const int resizehints = 0;

static const unsigned int borderpx = 1;
static const unsigned int snap = 32;

static const Button buttons[] = {
    // click, modifier, button, function, argument
    { ClkClientWin, MODIFIER, Button1, movemouse, { 0 } },
    { ClkClientWin, MODIFIER, Button3, resizemouse, { 0 } },
    { ClkClientWin, MODIFIER, Button2, togglefloating, { 0 } },

    { ClkTagBar, MODIFIER, Button1, tag, { 0 } },
    { ClkTagBar, MODIFIER, Button3, toggletag, { 0 } },

    { ClkTagBar, 0, Button1, view, { 0 } },
    { ClkTagBar, 0, Button3, toggleview, { 0 } },
};

static char dmenumon[2] = "0";
static const char* dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };

static const char* fonts[] = {
    "monospace:size=10",
    "Source Han Sans JP:size=10"
};

static const Layout layouts[] = {
    // symbol, function
    { "[]=", tile },
    { "><>", NULL },
    { "[M]", monocle },
};

static const Key keys[] = {
    // modifier, key, function, argument
    { MODIFIER, XK_comma, focusmon, { .i = -1 } },
    { MODIFIER, XK_period, focusmon, { .i = +1 } },
    { MODIFIER | ShiftMask, XK_comma, tagmon, { .i = -1 } },
    { MODIFIER | ShiftMask, XK_period, tagmon, { .i = +1 } },

    { MODIFIER, XK_k, focusstack, { .i = -1 } },
    { MODIFIER, XK_j, focusstack, { .i = +1 } },

    { MODIFIER | ShiftMask, XK_m, incnmaster, { .i = -1 } },
    { MODIFIER, XK_m, incnmaster, { .i = +1 } },
    { MODIFIER, XK_h, setmfact, { .f = -0.05 } },
    { MODIFIER, XK_l, setmfact, { .f = +0.05 } },

    { MODIFIER | ShiftMask, XK_q, killclient, { 0 } },
    { MODIFIER | ShiftMask, XK_space, togglefloating, { 0 } },
    { MODIFIER, XK_Return, zoom, { 0 } },

    { MODIFIER | ShiftMask, XK_r, restart, { 0 } },
    { MODIFIER | ShiftMask, XK_e, quit, { 0 } },

    { MODIFIER, XK_space, setlayout, { 0 } },
    { MODIFIER, XK_s, setlayout, { .v = &layouts[0] } },
    { MODIFIER, XK_f, setlayout, { .v = &layouts[1] } },
    { MODIFIER, XK_t, setlayout, { .v = &layouts[2] } },
    { MODIFIER, XK_b, togglebar, { 0 } },

#define SET_TAG_KEY(KEY, TAG) \
    { MODIFIER, KEY, view, { .ui = 1 << TAG } }, \
    { MODIFIER | ControlMask, KEY, toggleview, { .ui = 1 << TAG } }, \
    { MODIFIER | ShiftMask, KEY, tag, { .ui = 1 << TAG } }, \
    { MODIFIER | ControlMask | ShiftMask, KEY, toggletag, { .ui = 1 << TAG } }
    { MODIFIER, XK_Tab, view, { 0 } },

    SET_TAG_KEY(XK_1, 0),
    SET_TAG_KEY(XK_2, 1),
    SET_TAG_KEY(XK_3, 2),
    SET_TAG_KEY(XK_4, 3),
    SET_TAG_KEY(XK_5, 4),
    SET_TAG_KEY(XK_6, 5),
    SET_TAG_KEY(XK_7, 6),
    SET_TAG_KEY(XK_8, 7),
    SET_TAG_KEY(XK_9, 8),
    SET_TAG_KEY(XK_0, 9),
#undef SET_TAG_KEY

#define SPAWN(...) spawn, { .v = (const char*[]) { __VA_ARGS__, NULL } }
    { MODIFIER, XK_d, spawn, { .v = dmenucmd } },
    { MODIFIER | ShiftMask, XK_Return, SPAWN("st") },
#undef SPAWN
};

static const float mfact = 0.55;
static const int nmaster = 1;

static const Rule rules[] = {
    // class, instance, title, tags mask, is floating, monitor
    { NULL, NULL, NULL, 0, 0, -1 },
};

static const int showbar = 1;
static const int topbar = 1;

static const char sora_background[] = "#11111f";
static const char sora_foreground[] = "#cbddfd";
static const char sora_black[] = "#14151a";
static const char sora_green[] = "#11da86";

static const char* colors[][3] = {
    // [scheme] = { foreground, background, border },
    [SchemeNorm] = { sora_foreground, sora_background, sora_background },
    [SchemeSel] = { sora_green, sora_background, sora_green },
    [SchemeTagSel] = { sora_black, sora_green, sora_green },
};

static const char* tags[] = {
    "一", "二", "三", "四", "五", "六", "七", "八", "九", "十"
};

#undef MODIFIER
