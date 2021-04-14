const passport = require("passport");
const GoogleStrategy = require("passport-google-oauth20").Strategy;

passport.serializeUser(function (user, done) {
    done(null, user);
});

passport.deserializeUser(function (user, done) {
    done(null, user);
});

passport.use(
    new GoogleStrategy(
        {
            clientID:
                "516431102680-9qq573ee756jk43arnfdi3v87lciljj8.apps.googleusercontent.com",
            clientSecret: "1qC6jP5yEZMLrPddozkRfvTR",
            callbackURL: "http://localhost:3000/auth/google/callback",
        },
        function (accessToken, refreshToken, profile, cb) {
            return cb(null, profile);
        }
    )
);
