const express = require('express');
const app = express();
const port = 3000;

app.use(express.json());

// Klientdagi SessionManager murojaat qiladigan asosiy manzil (endpoint)
app.post('/session/claim', (req, res) => {
    const token = req.body.token;
    console.log(`[Backend] Klientdan token qabul qilindi: ${token}`);

    if (!token) {
        console.log('[Backend] Xatolik: So`rovda token topilmadi.');
        return res.status(400).json({ error: 'Token topilmadi' });
    }

    // BU YERDA KELAJAKDA TOKENNI TEKSHIRISH VA VM QIDIRISH MANTIG'I BO'LADI
    // Hozircha, har qanday token uchun sinov javobini qaytaramiz.

    console.log("[Backend] Sinov uchun javob yuborilmoqda...");
    res.json({
        vmHost: "127.0.0.1", // Hozircha o'zimizning kompyuter manzilini beramiz
        sessionId: `session_${Date.now()}`
    });
});

app.listen(port, () => {
    console.log(`[Backend] X.O.N Cloud Gaming backend sinov uchun ${port}-portda ishga tushdi`);
});
