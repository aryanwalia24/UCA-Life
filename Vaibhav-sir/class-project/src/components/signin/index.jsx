import { useRef, useState } from "react";
import { PageTitle } from "../elements/pageTitle";

export function SignIn() {
  const emailRef = useRef(null);
  const passwordRef = useRef(null);
  const [showSuccessAlert, setShowSuccessAlert] = useState(false);
  const [showFailureAlert, setShowFailureAlert] = useState(false);

  const signInHandler = async (event) => {
    event.preventDefault();

    var formValuesObject = {
      email: emailRef.current.value,
      password: passwordRef.current.value,
    };

    if (formValuesObject.email && formValuesObject.password) {
      try {
        const response = await fetch("http://localhost:8080/users/signin", {
          method: "POST",
          headers: {
            "Content-Type": "application/json",
          },
          body: JSON.stringify(formValuesObject),
        });

        if (response.ok) {
          const data = await response.json();
          setShowSuccessAlert(true);
          setShowFailureAlert(false);
          console.log("Login successful:", data);
          // Here you can add logic to store user data in state/localStorage
          // and redirect to another page if needed
        } else {
          setShowSuccessAlert(false);
          setShowFailureAlert(true);
        }
      } catch (error) {
        console.error("Error:", error);
        setShowSuccessAlert(false);
        setShowFailureAlert(true);
      }
    } else {
      setShowFailureAlert(true);
    }
  };

  return (
    <>
      <PageTitle>Sign In</PageTitle>

      {showSuccessAlert && (
        <div className="alert alert-success" role="alert">
          Login successful!
        </div>
      )}

      {showFailureAlert && (
        <div className="alert alert-danger" role="alert">
          Invalid email or password
        </div>
      )}

      <form className="g-3" onSubmit={signInHandler}>
        <div className="row justify-content-md-center">
          <div className="col-6">
            <label htmlFor="inputEmail4" className="form-label">
              Email
            </label>
            <input
              type="email"
              className="form-control"
              id="inputEmail4"
              ref={emailRef}
            />
          </div>
        </div>
        <div className="row justify-content-md-center">
          <div className="col-6">
            <label htmlFor="inputPassword4" className="form-label">
              Password
            </label>
            <input
              type="password"
              className="form-control"
              id="inputPassword4"
              ref={passwordRef}
            />
          </div>
        </div>
        <div className="row justify-content-md-center mt-3">
          <div className="col-2 justify-content-md-center">
            <button type="submit" className="btn btn-primary">
              Sign In
            </button>
          </div>
        </div>
      </form>
    </>
  );
}