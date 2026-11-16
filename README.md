# Guild Window Renewal

Yenilenmiş lonca penceresi. Başvurular, rütbe yetkileri, beceri ağacı, lonca mağazası, lonca görevleri ve bağış sistemi.

![Önizleme](preview.png)
![Önizleme](preview2.png)
![Önizleme](preview3.png)
![Önizleme](preview4.png)
![Önizleme](preview5.png)

---

## Ne var?

- Yeni lonca penceresi (`uiguildrenewal.py`)
- Lonca başvuru sistemi (`uiguildapplication.py`)
- Rütbe ayarları: 9 yetki
- Lonca beceri ağacı, mağaza, görevler, bağış (altın / gümüş)
- Fısıltı penceresinden loncaya davet
- PNG lonca logosu yükleme

## Paket yapısı

```
01. Svn/          → Client & Game source (Ara / Altına ekle / Bul / Değiştir patch dosyaları + yeni dosyalar)
02. Client/       → root, uiscript, locale, d_/ymir work assetleri
03. Server/       → MySQL tabloları, quest ve sunucu verileri
Added/            → Değişikliklerin uygulanmış hali (tam dosyalar, karşılaştırma için)
```

## Flagler

**Client** (`Locale_inc.h`):
- `ENABLE_GUILD_APPLICATION`
- `ENABLE_GUILD_GRADE_RENEWAL`
- `ENABLE_GUILD_MARK_PNG`
- `ENABLE_GUILD_WINDOW_RENEWAL`

**Game** (`service.h`):
- `ENABLE_WHISPER_GUILD_INVITE`
- `ENABLE_GUILD_GRADE_RENEWAL`
- `ENABLE_GUILD_SKILL_TREE`
- `ENABLE_GUILD_SHOP`
- `ENABLE_GUILD_QUEST`
- `ENABLE_GUILD_DONATION`
- `ENABLE_GUILD_APPLICATION`

Client ve game tarafında aynı isimli flagler birlikte açık olmalı; tek taraf açıkken paket / komut uyumsuzluğu olur.

## Kurulum (kısaca)

1. `01. Svn` altındaki patch dosyalarını kendi source ağacına uygula. Her blokta `// Ara:` satırlarını bul, `// Altına ekle:` kısmını altına ekle; `// Bul:` / `// Degistir:` bloklarında bulduğun satırları verilen blokla değiştir.
2. Yeni dosyaları (`guild_application.cpp`, `guild_application.h`, `guild_donation.cpp`, `guild_donation.h`, `guild_quest.cpp`, `guild_quest.h`, `guild_shop.cpp`, `guild_shop.h`, `guild_skill.cpp`, `guild_skill.h`) ilgili klasöre kopyala; game için `Makefile`, client için `vcxproj.txt` notuna göre projeye ekle.
3. `02. Client/root` ve `02. Client/uiscript` içindeki tam dosyaları pack'e kopyala, patch dosyalarını (`# Ara:` / `# Altına ekle:`) kendi dosyalarına uygula.
4. `02. Client/locale/<dil>/` satırlarını kendi locale dosyalarının sonuna ekle.
5. `02. Client/d_/ymir work/` görsellerini pack'e ekle (`d:/ymir work/...`).
6. `03. Server` içindeki SQL ve verileri sunucuya uygula.
7. Client + game + db rebuild, pack güncelle.

## Bağımlılıklar

- `uimessengerrenewal.py`, `uiwhispermessenger.py` (Chat Tabs & Whisper Messenger paketinde)
- `uicharacterdetails.py` (karakter detay penceresi)
- `uimessengerrenewal.py` patch'i yalnızca **Chat Tabs & Whisper Messenger** paketi kuruluysa gerekli.

## Notlar

- Locale dosyalarında yalnızca bu sisteme ait anahtarlar var; `new_locale_*` kendi eklediğimiz, `locale_game` / `locale_interface` resmi istemcide olmayan anahtarlar. Türkçe dosyalar cp1254.
- Patch'lerde başka sistemlere ait satırlar görürsen (farklı `#ifdef`), o sistem sende yoksa yok say.
- Fork farklıysa paket header / struct sıralamasını kontrol et.

---

## İletişim

Sorular için Discord'dan yazabilirsin.

| | |
|---|---|
| GitHub | [github.com/ybeststudio](https://github.com/ybeststudio) |
| Discord | [discord.gg/NXmc6JrwYr](https://discord.gg/NXmc6JrwYr) |
| Discord ID | `beststudio` |
| Web | [bestpro.dev](https://bestpro.dev) |
| TurkMMO | [Best Studio](https://forum.turkmmo.com/uye/2104546-best-studio/) |
| YouTube | [@ybeststudio](https://www.youtube.com/@ybeststudiotr) |
| Instagram | [@ybeststudio](https://www.instagram.com/ybeststudio) |
| Facebook | [ybeststudio](https://www.facebook.com/ybeststudio/) |
| Twitter | [@ybeststudio](https://twitter.com/ybeststudio) |
| TikTok | [@ybeststudio](https://tiktok.com/@ybeststudio) |

---

**Best Studio** — Metin2 private server çözümleri
