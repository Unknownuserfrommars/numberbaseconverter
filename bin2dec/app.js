document.addEventListener("DOMContentLoaded", () => {
  const form = document.getElementById("form");
  const input = document.getElementById("binaryInput");
  const errorEl = document.getElementById("error");
  const resultWrap = document.getElementById("resultWrap");
  const resultEl = document.getElementById("result");

  const isBinary = (s) => /^[01]+$/.test(s);

  function convert() {
    const raw = input.value.trim();

    // Clear state when empty
    if (raw === "") {
      errorEl.hidden = true;
      resultWrap.hidden = true;
      resultEl.textContent = "";
      return;
    }

    if (!isBinary(raw)) {
      errorEl.textContent = "Invalid input: only 0 and 1 are allowed.";
      errorEl.hidden = false;
      resultWrap.hidden = true;
      return;
    }

    try {
      // BigInt handles arbitrarily long binaries; leading zeros are naturally ignored.
      const decimalStr = BigInt("0b" + raw).toString(10);
      resultEl.textContent = decimalStr;
      resultWrap.hidden = false;
      errorEl.hidden = true;
    } catch (e) {
      errorEl.textContent = "Conversion error. Please check your input.";
      errorEl.hidden = false;
      resultWrap.hidden = true;
    }
  }

  // Convert on submit and as you type (for instant feedback)
  form.addEventListener("submit", (e) => {
    e.preventDefault();
    convert();
  });

  input.addEventListener("input", () => {
    // Live update if valid; hide result on invalid
    const v = input.value.trim();
    if (v === "") {
      errorEl.hidden = true;
      resultWrap.hidden = true;
      resultEl.textContent = "";
      return;
    }
    if (isBinary(v)) {
      convert();
    } else {
      errorEl.textContent = "Invalid input: only 0 and 1 are allowed.";
      errorEl.hidden = false;
      resultWrap.hidden = true;
    }
  });

  // Focus the input on load
  input.focus();
});
