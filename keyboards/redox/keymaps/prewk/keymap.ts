
const shift = (k: string) => `S(${k})`;
const opt = (k: string) => `A(${k})`;
const cmd = (k: string) => `G(${k})`;

enum Layer {
    Qwerty,
    Symbol,
    Navigation,
    Numpad,
}

const layerTap = (layer: Layer, tap: string) => `LT(${layer}, ${tap})`;

const qwertyKeys = [
    [`'`, 'KC_NUHS'],
    [`1`, 'KC_1'],
    [`2`, 'KC_2'],
    [`3`, 'KC_3'],
    [`4`, 'KC_4'],
    [`5`, 'KC_5'],
    [`6`, 'KC_6'],
    [`7`, 'KC_7'],
    [`8`, 'KC_8'],
    [`9`, 'KC_9'],
    [`0`, 'KC_0'],
    [`+`, 'KC_MINS'],
    [`⇥`, layerTap(Layer.Numpad, 'KC_TAB')],
    ['q', 'KC_Q'],
    ['w', 'KC_W'],
    ['e', 'KC_E'],
    ['r', 'KC_R'],
    ['t', 'KC_T'],
    ['📝', cmd('KC_NUBS')],
    ['📝', cmd('KC_NUBS')],
];

const qwertyMap = `
    ' 1 2 3 4 5              6 7 8 9 0 +
    ⇥ q w e r t 📝         📝 y u i o p å
   ␛ a s d f g ⌦          ⌫  h j k l ö ä
   ⬆ z x c v b 🧭 🔢    🔢 🧭 n m , . - ⬆
   ＾ < > ⌥  ⌘   _ ↩     ↩ _  ⌘ ⬅️ ⬇️ ⬆️ ➡️
`;
