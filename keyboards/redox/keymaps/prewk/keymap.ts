
const shift = (k) => `S(${k})`;
const opt = (k) => `A(${k})`;
const cmd = (k) => `G(${k})`;
const layerTap = (layer, tap) => `LT(${layer}, ${tap})`;
const toggleLayer = (layer) => `TG(${layer})`;
const sendString = (sendString) => ({ type: 'pressed', c: `SEND_STRING(${sendString})` });
const tapCodes = (chars) => ({ type: 'pressed', c: chars.map(char => 'tap_code16(' + char + ');\n')})

const basic = {
    ...['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1','2','3','4','5','6','7','8','9','0',
    'f1', 'f2', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8', 'f9', 'f10', 'f11', 'f12'].reduce((obj, char) => ({
        ...obj,
        [char]: `KC_${char.toLocaleUpperCase()}`,
        [char.toLocaleUpperCase()]: `KC_${char.toLocaleUpperCase()}`,
    }), {}),
}
const swedish = {
    ...basic,
    'å': 'KC_LBRC',
    'Å': 'KC_LBRC',
    'ä': 'KC_QUOT',
    'Ä': 'KC_QUOT',
    'ö': 'KC_SCLN',
    'Ö': 'KC_SCLN',
    '§': 'KC_NUBS',
    '<': 'KC_GRV',
    '>': 'S(KC_GRV)',
    "'": 'KC_NUHS',
    '¨': 'KC_RBRC',
    '´': 'KC_EQL',
    '`': 'S(KC_EQL)',
    '+': 'KC_MINS',
    '-': 'KC_SLSH',
    '(': 'S(KC_8)',
    ')': 'S(KC_9)',
    '{': 'S(A(KC_8))',
    '}': 'S(A(KC_9))',
    '[': 'A(KC_8)',
    ']': 'A(KC_9)',
    '@': 'A(KC_2)',
    '$': 'A(KC_4)',
    '*': 'S(KC_NUHS)',
    '~': 'A(KC_RBRC)',
    ':': 'S(KC_DOT)',
    '=': 'S(KC_0)',
    '/': 'S(KC_7)',
    '|': 'A(KC_7)',
    '\\': 'S(A(KC_7))',
    '?': 'S(KC_MINS)',
    ',': 'KC_COMM',
};

const Layer = {
    Qwerty: 0,
    Symbol: 1,
    Navigation: 2,
    Numpad: 3,
}

const qwerty = {
    layer: Layer.Qwerty,
    keys: {
        ...swedish,
        '⇥': layerTap(Layer.Numpad, 'KC_TAB'),
        '📝': cmd('KC_NUBS'),
        '␛': 'KC_ESC',
        '⌦': 'KC_DEL',
        '⌫': 'KC_BSPC',
        'L⬆': 'KC_LSFT',
        '🧭': toggleLayer(Layer.Navigation),
        '🆙': 'KC_CAPS',
        '⬆R': 'KC_RSFT',
        '^' :'KC_LCTRL',
        '<' :swedish["<"],
        '>': shift(swedish["<"]),
        '⌥': 'LALT_T(KC_DOT)',
        'L⌘': 'KC_LCMD',
        '_': layerTap(Layer.Navigation, 'KC_SPC'),
        '↩': layerTap(Layer.Symbol, 'KC_ENT'),
        '⌘R': 'KC_RCMD',
        '⬅️': 'RALT_T(KC_LEFT)',
        '⬇️️': 'KC_DOWN',
        '⬆️': 'KC_UP',
        '➡️': 'RCTL_T(KC_RIGHT)',
        '?️': 'KC_TRNS',
    },
    map: `
        ' 1 2 3 4 5              6 7 8 9 0 +
        ⇥ q w e r t 📝         📝 y u i o p å
       ␛ a s d f g ⌦          ⌫  h j k l ö ä
      L⬆ z x c v b  ? 🆙    ~ / n m , . - ⬆R
       ＾ < > ⌥  L⌘  _ ↩     ↩ _ ⌘R ⬅️ ⬇️ ⬆️ ➡️`
}

const symbol = {
    layer: Layer.Symbol,
    keys: {
        ...swedish,
        "'": tapCodes([swedish['`'], 'KC_SPC']),
        '_': 'KC_TRNS',
        '⌫': 'G(KC_BSPC)',
        '=>': tapCodes([swedish['='], swedish['>'], 'KC_SPC']),
        "'''": tapCodes([swedish['`'], 'KC_SPC', swedish['`'], 'KC_SPC', swedish['`'], 'KC_SPC']),
        '-[]': tapCodes([swedish['-'], 'KC_SPC', swedish['['], 'KC_SPC', swedish[']'], 'KC_SPC']),
        '$()': tapCodes([swedish['$'], swedish['('], swedish[')']]),
        '⌘Z': 'G(Z)',
        '⌘X': 'G(X)',
        '⌘C': 'G(C)',
        '⌘V': 'G(V)',
    },
    map: `
        ' f1 f2 f3 f4 f5              f6   f7 f8 f9 f10 f11
      ''' (  {  [  <  _  _         _  ===  >  ]  }  )   f12
      -[] @  $  *  ~  :  _         ⌫  =    /  |  \  ?   => 
      $() ⌘Z ⌘X ⌘C ⌘V _  _ _     _ _  _    _  _  _  _   _
        _ _  _  _    _   _ _     _ _     _    _  _  _   _`
}

const nav = {
    layer: Layer.Navigation,
    keys: {
        ...swedish,
        '⌫': 'G(KC_BSPC)',
        '⏪': 'A(KC_LEFT)',
        '⏫': 'KC_PGUP',
        '⏬': 'KC_PGDN',
        '⏩': 'A(KC_RIGHT)',
        '⬅️': 'KC_LEFT',
        '⬇️': 'KC_DOWN',
        '⬆️': 'KC_UP',
        '➡️ ': 'KC_RIGHT',
        '⌘Z': 'G(Z)',
        '⌘X': 'G(X)',
        '⌘C': 'G(C)',
        '⌘V': 'G(V)',
    },
    map: `
        _ f1 f2 f3 f4 f5              f6 f7 f8 f9 f10 ´
        _ (  {  [  <  _  _         _  _  ⏪ ⏫  ⏬  ⏩ ¨
        _ @  $  *  ~  :  _         ⌫  =  ⬅️ ⬇️  ⬆️  ➡️ _ 
        _ ⌘Z ⌘X ⌘C ⌘V _  _ _     _ _  _  _  _  _  _   _
        _ _  _  _    _   _ _     _ _   _    _  _  _   _`
}

const num = {
    layer: Layer.Numpad,
    keys: {
        ...swedish,
        '⏮': 'KC_MPRV',
        '⏭': 'KC_MNXT',
        '🔊': 'KC_VOLU',
        '🔉': 'KC_VOLD',
        '🔇': 'KC_MUTE',
        '⏯': 'KC_MPLY',
        'E': sendString('engagement'),
    },
    map: `
        _ _ _ _ ⏮ ⏭             _ _ _ _ _ _
        _ _ _ E _ _ 🔊         🔇 _ 7 8 9 - _
        _ _ _ _ _ _ 🔉         ⏯ _ 4 5 6 + _ 
        _ _ _ _ _ _ _ _      _ _ _ 1 2 3 ↩ _
        _ _ _ _  _  _ _      _ _  0  _ , _ _️`
}