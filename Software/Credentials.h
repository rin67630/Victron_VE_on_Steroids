#define WIFI_SSID            "Secret"  // Change it your own SSID
#define WIFI_PASS            "Secret"  // Change it your own Password

// ***Time zones***
#define NTP_SERVER "de.pool.ntp.org"   // Change de. to your own country
#define TZ             1                // (utc+) TZ in hours
#define DST_MN         60
#define GMT_OFFSET_SEC 3600 * TZ
#define DAYLIGHT_OFFSET_SEC 60 * DST_MN

//Thinger
#define THINGER_USERNAME           "Secret"  // Change it your own UserName
#define THINGER_DEVICE_CREDENTIALS "Secret"  // Change it your own Credential
#define THINGER_DEVICE             DEVICE_NAME

#define INFLUXDB_URL               "https://eu-central-1-1.aws.cloud2.influxdata.com"
#define INFLUXDB_TOKEN             "Secret"  // Change it your own token
#define INFLUXDB_ORG               "your@email"
#define INFLUXDB_BUCKET            "Steroids Bucket"

//Location for weather
#define OPEN_WEATHER_MAP_APP_ID      "Secret"    // Change it your own ID
#define OPEN_WEATHER_MAP_LOCATION_ID "TownCode"  // Change it your own TownCode
#define OPEN_WEATHER_MAP_LANGUAGE    "en"
#define OPEN_WEATHER_MAP_UNITS       "metric"    //Americans: learn Metric ;-)
