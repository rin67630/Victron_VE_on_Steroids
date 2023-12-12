{
  "controls": {
    "aggregation": {
      "auto": false,
      "period": "auto"
    },
    "timespan": {
      "magnitude": "day",
      "mode": "relative",
      "period": "latest",
      "value": 7
    }
  },
  "description": "Frontpage",
  "name": "Frontpage",
  "properties": {
    "background_image": "#000000",
    "border_radius": "10px",
    "columns": 5,
    "hide_header": true,
    "row_height": 24
  },
  "tabs": [
    {
      "icon": "fas fa-tachometer-alt",
      "name": "Test2",
      "widgets": [
        {
          "layout": {
            "col": 3,
            "row": 0,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Backup Voltage"
          },
          "properties": {
            "color": "#01df23",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "V",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "Vac",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "Vac",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 3,
            "row": 5,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Backup Current"
          },
          "properties": {
            "color": "#df3e12",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "A",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "Iac",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "Iac",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 0,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Battery Voltage"
          },
          "properties": {
            "color": "#01df23",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "V",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "Vbat",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "Vbat",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 0,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Load Voltage"
          },
          "properties": {
            "color": "#01df23",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "V",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "Vaux",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "Vaux",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 0,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Panel Voltage"
          },
          "properties": {
            "color": "#01df23",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "V",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "Vpan",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "Vpan",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 3,
            "row": 10,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Backup Power"
          },
          "properties": {
            "color": "#4852df",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "W",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "Wac",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "Wac",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 5,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Battery Current"
          },
          "properties": {
            "color": "#df3e12",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "A",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "Ibat",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "Ibat",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 5,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Load Current"
          },
          "properties": {
            "color": "#df3e12",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "A",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "Iaux",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "Iaux",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 5,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Panel Current"
          },
          "properties": {
            "color": "#df3e12",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "A",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "IPan",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "IPan",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 10,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Panel Power"
          },
          "properties": {
            "color": "#4852df",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "W",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "Wpan",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "Wpan",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 10,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Battery Power"
          },
          "properties": {
            "color": "#4852df",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "W",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "Wbat",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "Wbat",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 10,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Load Power"
          },
          "properties": {
            "color": "#4852df",
            "decimal_places": 2,
            "icon": "",
            "size": "75px",
            "unit": "W",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "Waux",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "Waux",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 10,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Conversion Effcy"
          },
          "properties": {
            "color": "#a3690f",
            "decimal_places": 0,
            "icon": "",
            "size": "75px",
            "unit": "%",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "efficiency",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "efficiency",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 0,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "Battery int. Resistance"
          },
          "properties": {
            "color": "#a3690f",
            "decimal_places": 3,
            "icon": "",
            "size": "75px",
            "unit": "Ω",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "ohm",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "ohm",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 5,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#404040",
            "title": "% Charged"
          },
          "properties": {
            "color": "#a3690f",
            "decimal_places": 0,
            "icon": "",
            "size": "75px",
            "unit": "%",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device": {
                "id": "Steroids",
                "interval": 5,
                "mapping": "percent_charged",
                "resource": "measure",
                "update": "interval",
                "user": "rin67631"
              },
              "name": "percent_charged",
              "skipCurrent": 1,
              "source": "device"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 4,
            "row": 39,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#808080",
            "title": "Weather"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "50px",
            "unit": "",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "Steroids",
                "mapping": "summary",
                "property": "persistance",
                "user": "rin67631"
              },
              "source": "device_property"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 39,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#808080",
            "title": "Outside rel. humidity"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "75px",
            "unit": "%",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "Steroids",
                "mapping": "humidity",
                "property": "persistance",
                "user": "rin67631"
              },
              "source": "device_property"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 1,
            "row": 39,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#808080",
            "title": "Outside Temperature"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "75px",
            "unit": "°C",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "Steroids",
                "mapping": "temperature",
                "property": "persistance",
                "user": "rin67631"
              },
              "source": "device_property"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 2,
            "row": 39,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#808080",
            "title": "Atm. Pressure"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "75px",
            "unit": "hPa",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "Steroids",
                "mapping": "pressure",
                "property": "persistance",
                "user": "rin67631"
              },
              "source": "device_property"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 3,
            "row": 39,
            "sizeX": 1,
            "sizeY": 5
          },
          "panel": {
            "color": "#808080",
            "title": "Wind"
          },
          "properties": {
            "color": "#1E313E",
            "decimal_places": 0,
            "icon": "",
            "size": "75px",
            "unit": "m/s",
            "unit_size": "20px",
            "weight": "font-thin"
          },
          "sources": [
            {
              "device_property": {
                "device": "Steroids",
                "mapping": "wind",
                "property": "persistance",
                "user": "rin67631"
              },
              "source": "device_property"
            }
          ],
          "type": "text"
        },
        {
          "layout": {
            "col": 0,
            "row": 15,
            "sizeX": 5,
            "sizeY": 24
          },
          "panel": {
            "color": "#606060",
            "showOffline": {
              "type": "none"
            }
          },
          "properties": {
            "axis": true,
            "fill": true,
            "legend": true,
            "multiple_axes": false
          },
          "sources": [
            {
              "aggregation": {},
              "bucket": {
                "backend": "dynamodb",
                "id": "MIN",
                "mapping": "Vbat",
                "user": "rin67631"
              },
              "color": "#e1d50d",
              "name": "Vbat",
              "source": "bucket",
              "timespan": {
                "magnitude": "day",
                "mode": "configurable",
                "period": "latest",
                "value": 2
              }
            },
            {
              "aggregation": {},
              "bucket": {
                "backend": "dynamodb",
                "id": "MIN",
                "mapping": "Wpan",
                "user": "rin67631"
              },
              "color": "#0df525",
              "name": "Wpan",
              "source": "bucket",
              "timespan": {
                "magnitude": "day",
                "mode": "configurable",
                "period": "latest",
                "value": 2
              }
            },
            {
              "aggregation": {},
              "bucket": {
                "backend": "dynamodb",
                "id": "MIN",
                "mapping": "Wac",
                "user": "rin67631"
              },
              "color": "#bf320c",
              "name": "Wac",
              "source": "bucket",
              "timespan": {
                "magnitude": "day",
                "mode": "configurable",
                "period": "latest",
                "value": 2
              }
            }
          ],
          "type": "chart"
        }
      ]
    }
  ]
}
