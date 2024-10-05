{
	"controls": {
		"aggregation": {
			"auto": true,
			"period": "1m"
		},
		"timespan": {
			"magnitude": "day",
			"mode": "relative",
			"period": "latest",
			"value": 90
		}
	},
	"description": "Power Supply Monitoring",
	"name": "Power Supply Monitoring",
	"placeholders": {
		"sources": []
	},
	"properties": {
		"background_image": "#333333",
		"border_radius": "10px",
		"columns": 4
	},
	"tabs": [
		{
			"icon": "fas fa-tachometer-alt",
			"name": "LongTerm",
			"widgets": [
				{
					"api": {},
					"layout": {
						"col": 0,
						"row": 0,
						"sizeX": 4,
						"sizeY": 27
					},
					"panel": {
						"color": "#1d1d1d",
						"currentColor": "#1d1d1d",
						"currentSubtitle": "",
						"currentTitle": "Voltage",
						"showOffline": {
							"type": "none"
						},
						"title": "Voltage",
						"updateTs": 1727971199953
					},
					"properties": {
						"axis": true,
						"fill": true,
						"legend": false,
						"multiple_axes": false,
						"options": "var options = {\n    series: series,\n    chart: {\n        type: 'area'\n    },\n    dataLabels: {\n        enabled: false\n    },\n    stroke: {\n        curve: 'smooth',\n        width: 2\n    },\n    xaxis: {\n        type: 'datetime',\n        labels: {\n            datetimeUTC: false\n        },\n        tooltip: {\n            enabled: true\n        }\n    },\n    yaxis: {\n        \"labels\": {\n            \"formatter\": function (val) {\n                return val.toFixed(2);\n            }\n\n        },\n        min: 11.6,\n        max: 14.6\n    },\n        grid: {\n        row: {\n            colors: ['#f3f3f3', 'transparent'],\n            opacity: 0.05\n        },\n    },\n    tooltip: {\n        x: {\n            format: 'dd/MM/yyyy HH:mm:ss'\n        }\n    }\n};",
						"yaxis": {
							"max": 14,
							"min": 11.7
						}
					},
					"sources": [
						{
							"$timespan": {
								"mode": "configurable"
							},
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"mapping": "BatV",
								"tags": {}
							},
							"color": "#08ef40",
							"name": "Voltage",
							"source": "bucket",
							"timespan": {
								"magnitude": "day",
								"mode": "relative",
								"period": "latest",
								"value": 30
							}
						}
					],
					"type": "apex_charts"
				},
				{
					"layout": {
						"col": 1,
						"row": 30,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Outdoor % Humidity"
					},
					"properties": {
						"majorTicks": 10,
						"max": 100,
						"min": 0,
						"plateColor": "#333333",
						"showValue": true,
						"textColor": "#ff8000",
						"tickColor": "#ff8000",
						"unit": "% Dew point"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "BluSCC",
								"mapping": "humidity",
								"property": "persistance"
							},
							"name": "Source 1",
							"source": "device_property"
						}
					],
					"type": "tachometer"
				},
				{
					"layout": {
						"col": 2,
						"row": 30,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Outd0or Air Pressure"
					},
					"properties": {
						"majorTicks": 25,
						"max": 1050,
						"min": 950,
						"plateColor": "#333333",
						"showValue": true,
						"textColor": "#00ff00",
						"tickColor": "#00ff00",
						"unit": "hPa"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "BluSCC",
								"mapping": "pressure",
								"property": "persistance"
							},
							"name": "Source 1",
							"source": "device_property"
						}
					],
					"type": "tachometer"
				},
				{
					"layout": {
						"col": 3,
						"row": 30,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Wind speed"
					},
					"properties": {
						"majorTicks": 3,
						"max": 30,
						"min": 0,
						"plateColor": "#333333",
						"showValue": true,
						"textColor": "#ffff00",
						"tickColor": "#ffff00",
						"unit": "m/Sec"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "BluSCC",
								"mapping": "wind",
								"property": "persistance"
							},
							"name": "Source 1",
							"source": "device_property"
						}
					],
					"type": "tachometer"
				},
				{
					"layout": {
						"col": 0,
						"row": 30,
						"sizeX": 1,
						"sizeY": 8
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"subtitle": "",
						"title": "Outdoor Temperature"
					},
					"properties": {
						"majorTicks": 10,
						"max": 40,
						"min": -10,
						"plateColor": "#333333",
						"showValue": true,
						"textColor": "#00ffff",
						"tickColor": "#00ffff",
						"unit": "° Celsius"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "BluSCC",
								"mapping": "temperature",
								"property": "persistance"
							},
							"name": "Source 1",
							"source": "device_property"
						}
					],
					"type": "tachometer"
				},
				{
					"layout": {
						"col": 0,
						"row": 27,
						"sizeX": 3,
						"sizeY": 3
					},
					"panel": {
						"color": "#ffffff",
						"colors": [
							{
								"color": "#ff0000",
								"max": 11,
								"min": 0
							},
							{
								"color": "#ff8000",
								"max": 12,
								"min": 11
							},
							{
								"color": "#ffff00",
								"max": 12.5,
								"min": 12
							},
							{
								"color": "#00c100",
								"max": 14,
								"min": 12.5
							},
							{
								"color": "#ff0000",
								"max": 20,
								"min": 14
							}
						],
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						},
						"showTs": true,
						"subtitle": "11: 0% ... 14: 100%",
						"title": "Battery Voltage"
					},
					"properties": {
						"icon": "",
						"iconSize": "",
						"max": 14,
						"min": 11,
						"unit": "V"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device": {
								"id": "BluSCC",
								"interval": 5,
								"mapping": "BatV",
								"resource": "measure",
								"update": "interval"
							},
							"name": "Source 1",
							"source": "device"
						}
					],
					"type": "progressbar"
				},
				{
					"layout": {
						"col": 3,
						"row": 27,
						"sizeX": 1,
						"sizeY": 3
					},
					"panel": {
						"color": "#111111",
						"currentColor": "#111111",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#00fb00",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device": {
								"id": "BluSCC",
								"interval": 300,
								"mapping": "BatV",
								"resource": "measure",
								"update": "interval"
							},
							"name": "Source 1",
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 38,
						"sizeX": 3,
						"sizeY": 2
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#12bcbc",
						"decimal_places": 0,
						"icon": "",
						"size": "48px",
						"unit_size": "16px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"mapping": "summary",
								"tags": {}
							},
							"color": "#1abc9c",
							"device": {
								"id": "DFLD20_04_CLI",
								"resource": "energy"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 38,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#333333",
						"currentColor": "#333333",
						"showOffline": {
							"type": "none"
						},
						"title": "N________________ E________________  S________________W________________N"
					},
					"properties": {
						"icon": "",
						"iconSize": "",
						"max": 360,
						"min": 0
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"mapping": "direction",
								"tags": {}
							},
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "progressbar"
				}
			]
		}
	],
	"widgets": [
		{
			"data": {
				"bucket": {
					"backend": "dynamodb",
					"id": "HOUR",
					"mapping": [
						"voltage",
						"current"
					],
					"user": "rin67630"
				},
				"source": "bucket"
			},
			"layout": {
				"col": 0,
				"row": 0,
				"sizeX": 6,
				"sizeY": 13
			},
			"panel": {
				"color": "#ffffff"
			},
			"properties": {
				"axis": true,
				"color": {
					"current": "#026cee",
					"temperature": "#ef0701",
					"voltage": "#23d004"
				},
				"fill": true,
				"legend": true,
				"multiple_axes": true,
				"timespan": {
					"magnitude": "month",
					"mode": "relative",
					"period": "latest",
					"value": 1
				}
			},
			"type": "chart"
		},
		{
			"data": {
				"bucket": {
					"backend": "dynamodb",
					"id": "DAY",
					"mapping": [
						"BV@0h",
						"BAhDay"
					],
					"user": "rin67630"
				},
				"source": "bucket"
			},
			"layout": {
				"col": 0,
				"row": 13,
				"sizeX": 6,
				"sizeY": 12
			},
			"panel": {
				"color": "#ffffff"
			},
			"properties": {
				"axis": true,
				"color": {
					"BAhDay": "#2475d7",
					"BV@0h": "#1ed004"
				},
				"fill": true,
				"legend": true,
				"multiple_axes": true,
				"timespan": {
					"magnitude": "month",
					"mode": "relative",
					"period": "latest",
					"value": 1
				}
			},
			"type": "chart"
		},
		{
			"data": {
				"device": {
					"id": "DFLD20_04_CLI",
					"interval": 3,
					"mapping": "power",
					"resource": "energy",
					"update": "interval",
					"user": "rin67630"
				},
				"source": "device"
			},
			"layout": {
				"col": 2,
				"row": 25,
				"sizeX": 1,
				"sizeY": 5
			},
			"panel": {
				"color": "#ffffff"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "75px",
				"unit": "W",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device": {
					"id": "DFLD20_04_CLI",
					"interval": 3,
					"mapping": "voltage",
					"resource": "energy",
					"update": "interval",
					"user": "rin67630"
				},
				"source": "device"
			},
			"layout": {
				"col": 0,
				"row": 25,
				"sizeX": 1,
				"sizeY": 5
			},
			"panel": {
				"color": "#ffffff"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 2,
				"icon": "",
				"size": "75px",
				"unit": "V",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		},
		{
			"data": {
				"device": {
					"id": "DFLD20_04_CLI",
					"interval": 3,
					"mapping": "current",
					"resource": "energy",
					"update": "interval",
					"user": "rin67630"
				},
				"source": "device"
			},
			"layout": {
				"col": 1,
				"row": 25,
				"sizeX": 1,
				"sizeY": 5
			},
			"panel": {
				"color": "#ffffff"
			},
			"properties": {
				"color": "#1E313E",
				"decimal_places": 3,
				"icon": "",
				"size": "75px",
				"unit": "A",
				"unit_size": "20px",
				"weight": "font-thin"
			},
			"type": "text"
		}
	]
}
