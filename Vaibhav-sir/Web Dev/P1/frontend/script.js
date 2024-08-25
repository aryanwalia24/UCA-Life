const button = document.getElementById("btn");
const cityInput = document.getElementById("city-input");
const cityName = document.getElementById("city-name");
const cityTime = document.getElementById("city-time");
const cityTemp = document.getElementById("city-temp");

// Function to fetch weather data
async function getData(location) {
  const response = await fetch(
    `https://api.weatherapi.com/v1/current.json?key=be2a0bb3aa434861a4f60039242907&q=${location}&aqi=yes`
  );
  return await response.json();
}

// Function to handle successful location retrieval
async function gotLocation(position) {
  try {
    const result = await getData(
      `${position.coords.latitude},${position.coords.longitude}`
    );
    updateUI(result);
  } catch (error) {
    console.error("Error fetching weather data:", error);
  }
}

// Function to update the UI with fetched weather data
function updateUI(result) {
  cityName.innerHTML = `${result.location.name}, ${result.location.region} ~ ${result.location.country}`;
  cityTime.innerHTML = `${result.location.localtime}`;
  cityTemp.innerHTML = `${result.current.temp_c}`;

  // Store data in localStorage
  localStorage.setItem("cityName", cityName.innerHTML);
  localStorage.setItem("cityTime", cityTime.innerHTML);
  localStorage.setItem("cityTemp", cityTemp.innerHTML);
}

// Function to handle location retrieval failure
function failedLocation() {
  console.log("Location access denied or unavailable");
}

// Event listener for button click
button.addEventListener("click", async () => {
  const city = cityInput.value.trim();
  if (city) {
    try {
      const result = await getData(city);
      updateUI(result);
    } catch (error) {
      console.error("Error fetching weather data:", error);
    }
  } else {
    navigator.geolocation.getCurrentPosition(gotLocation, failedLocation);
  }
});

// Check localStorage on page load and update UI if data exists
window.addEventListener("load", () => {
  const storedCityName = localStorage.getItem("cityName");
  const storedCityTime = localStorage.getItem("cityTime");
  const storedCityTemp = localStorage.getItem("cityTemp");

  if (storedCityName && storedCityTime && storedCityTemp) {
    cityName.innerHTML = storedCityName;
    cityTime.innerHTML = storedCityTime;
    cityTemp.innerHTML = storedCityTemp;
  }
});
